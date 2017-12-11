#define H_LEN 75
#define V_LEN 35
#define QUE 2000
#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QDebug>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trisol.h"
#include "kfsol.h"
#include <QFile>
#include <QTextStream>

pid_t pid_temp;
QString selectedMapPath = ":/img/9thfloor.png";
int Navi_Des_X;
int Navi_Des_Y;

struct st
{
    int i, j, parentqnum, d;
};
int Des_I, Des_J, Src_I, Src_J;
int wp, rp, last;

struct st route[QUE];
int chk[V_LEN][H_LEN];
int map[V_LEN][H_LEN];
int ans[V_LEN][H_LEN];
int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };


_circle c[3];
_dot predicted_dot;
SKalman1D kalman_filter[3] = {{-59,0.01,0.01,1},{-59,0.01,0.01,1},{-59,0.01,0.01,1}};
signed int device_x_pos[3] = {100,100,100};
signed int device_y_pos[3] = {100,100,100};
signed int tx_power[3] = {-59, -59, -59};
double cm_per_pixel = 5.8030;


void KalmanPredictUpdate1D(SKalman1D *kalman, double NewData);
void _solve_line(_circle c1, _circle c2, _line * l);
void _solve_dot(_line l1, _line l2, _dot * d);
void _solve_position(_circle * circle, _dot * ans);
void _solve_position(_circle * circle, _dot * ans);
double _rssi_to_dist(signed int rssi, signed int tx);
void PathFind(int I, int J, int n);
void injectMapData(void);
void FindDst(void);
void CheckPath(void);

void injectMapData()
{
    //qDebug() << "inject";
    QFile file("/home/pi/workspace/raspberry-pi-qt/final/mapdata.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        int k = 0;
        //qDebug() << "start";
        QTextStream stream(&file);
        QString dataString = stream.readAll();
        QChar * start = dataString.begin();
        QChar * end = dataString.end();
        //qDebug() << start << ", " << end;
        //qDebug() << *dataString.begin();

        for(; start != end ; ++start) {
            //qDebug() << (*start).digitValue();
            if((*start).digitValue() == -1) continue;
            map[k/75][k%75] = (*start).digitValue();
            k++;
        }
        file.close();
    }
}


int main(int argc, char *argv[])
{
    qDebug() << "sfdgljksdfghlkdfsghdsfkjghjdfk/;";
    pid_temp = fork();
    if (pid_temp == 0) {
        execlp("sudo", "sudo", "/home/pi/workspace/raspberrypi-bluetooth/bin/scan", NULL);
    }

    QApplication a(argc, argv);
    injectMapData();
    MainWindow w;
    w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    w.show();
    return a.exec();
}


void CheckPath(void) {
    if (last == -1) return;
    ans[route[last].i][route[last].j] = 2;
    last = route[last].parentqnum;
    for (;;) {
        if (last == -1) break;
        ans[route[last].i][route[last].j] = 1;
        last = route[last].parentqnum;
    }
    ans[Src_I][Src_J] = 2;
    return;
}

void FindDst(void)
{
    int ti, tj, td, k, ni, nj;

    wp = 0; rp = 0;
    memset(route, 0, sizeof(route));
    memset(chk, 0, sizeof(chk));
    memset(ans, 0, sizeof(ans));

    route[wp].parentqnum = -1;
    route[wp].i = Src_I;
    route[wp].j = Src_J;
    route[wp].d = 0;
    wp++;

    for (;;)
    {
        if (rp == wp) {
            last = -1;
            break;
        }

        ti = route[rp].i;
        tj = route[rp].j;
        td = route[rp].d;
        rp++;

        if (ti == Des_I && tj == Des_J) {
            last = rp;
            break;
        }

        for (k = 0; k < 4; k++)
        {
            ni = ti + dir[k][0];
            nj = tj + dir[k][1];
            if (map[ni][nj] == 0) continue;
            if (chk[ni][nj]) continue;
            chk[ni][nj] = 1;

            route[wp].i = ni;
            route[wp].j = nj;
            route[wp].d = td + 1;
            route[wp].parentqnum = rp - 1;
            wp++;
        }
    }
}


void KalmanPredictUpdate1D(SKalman1D* Kalman, double NewData)
{
    // Kalman gain
    double K;

    // Predict
    Kalman->P = Kalman->P + Kalman->Q;

    // Update
    K = Kalman->P / (Kalman->P + Kalman->R);
    Kalman->X = Kalman->X + K * (NewData - Kalman->X);
    Kalman->P = (1 - K) * Kalman->P;
}

void _solve_line(_circle c1, _circle c2, _line * l) {
    l->a = -2 * (c1.a - c2.a);
    l->b = -2 * (c1.b - c2.b);
    l->k = (c1.k*c1.k - c2.k*c2.k) - (c1.a*c1.a - c2.a*c2.a) - (c1.b*c1.b - c2.b*c2.b);
}

void _solve_dot(_line l1, _line l2, _dot * d) {
    double inv_factor = (l1.a * l2.b - l1.b * l2.a);
    d->x = (l2.b*l1.k - l1.b*l2.k) / inv_factor;
    d->y = (l1.a*l2.k - l2.a*l1.k) / inv_factor;
}

void _solve_position(_circle * circle, _dot * ans) {
    _line line[3];
    _solve_line(circle[0], circle[1], &line[0]);
    _solve_line(circle[1], circle[2], &line[1]);
    _solve_line(circle[2], circle[0], &line[2]);

    _dot dot[3];
    _solve_dot(line[0], line[1], &dot[0]);
    _solve_dot(line[1], line[2], &dot[1]);
    _solve_dot(line[2], line[0], &dot[2]);

    ans->x = (dot[0].x + dot[1].x + dot[2].x) / 3.0;
    ans->y = (dot[0].y + dot[1].y + dot[2].y) / 3.0;
}

double _rssi_to_dist(double rssi) {
    return pow( 10.0,( (-59.0-rssi)/20.0) );
}

/* ############## sample codes of trisol. ###################
_circle c[3] = { { 0, 0, 1 }, { 1, 4, 1 }, { 2, 0, 1 } };
_dot d;
_solve_position(c, &d);
qDebug("x = %.2f\ny = %.2f", d.x, d.y);
*/

/* ############## sample codes of kfsol. ####################
double sample[100];
for (int i = 0; i < 100; i++)
    sample[i] = (-10 + rand() % 201/10.0 );
    //sample[i] = i>50?50:i;

SKalman1D kalman;
kalman.X = 0;
kalman.Q = 10;
kalman.P = 10;
kalman.R = 200;

printf("now position = %.2f \n", kalman.X);
for (int i = 0; i < 100; i++) {
    KalmanPredictUpdate1D(&kalman, sample[i]);
    qDebug("now pos = %6.2f, real pos = %6.2f \n", kalman.X, sample[i]);
}
*/
