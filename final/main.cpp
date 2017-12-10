#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QDebug>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>

#include "trisol.h"
#include "kfsol.h"

pid_t pid_temp;
QString selectedMapPath = ":/img/9thfloor.png";

_circle c[3];
_dot predicted_dot;
SKalman1D kalman_filter[3] = {{-59,0.01,0.01,3},{-59,0.01,0.01,3},{-59,0.01,0.01,3}};
signed int device_x_pos[3] = {100,100,100};
signed int device_y_pos[3] = {100,100,100};
signed int tx_power[3] = {-54, -59, -59};
double cm_per_pixel = 5.8030;

//double PiZero_X_value;
//double PiOneCaseO_X_value;
//double PiOneCaseX_X_value;

void KalmanPredictUpdate1D(SKalman1D *kalman, double NewData);
void _solve_line(_circle c1, _circle c2, _line * l);
void _solve_dot(_line l1, _line l2, _dot * d);
void _solve_position(_circle * circle, _dot * ans);
void _solve_position(_circle * circle, _dot * ans);
double _rssi_to_dist(signed int rssi, signed int tx);

int main(int argc, char *argv[])
{
    pid_temp = fork();
    if (pid_temp == 0) {
        execlp("sudo", "sudo", "/home/pi/workspace/raspberrypi-bluetooth/bin/scan", NULL);
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    w.show();
    return a.exec();
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
    //return 10.0;
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
