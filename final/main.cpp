#include "mainwindow.h"
#include <QApplication>
#include "kfsol.h"

void KalmanPredictUpdate1D(SKalman1D* Kalman, double NewData);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    w.show();



    return a.exec();
}


void KalmanPredictUpdate1D(SKalman1D* Kalman, double NewData)
{
    double K;	// Kalman gain

    // Predict
    // Kalman->X 는 1차원에서 그냥 예전값과 동일할거라 예측됨(?)
    Kalman->P = Kalman->P + Kalman->Q;

    // Update
    K = Kalman->P / (Kalman->P + Kalman->R);
    Kalman->X = Kalman->X + K * (NewData - Kalman->X);
    Kalman->P = (1 - K) * Kalman->P;
}
