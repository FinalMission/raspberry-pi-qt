#include "kfsol.h"

void KalmanPredictUpdate1D(SKalman1D* Kalman, double NewData)
{
	double K;	// Kalman gain

	// Predict
	// Kalman->X �� 1�������� �׳� �������� �����ҰŶ� ������(?)
	Kalman->P = Kalman->P + Kalman->Q;

	// Update
	K = Kalman->P / (Kalman->P + Kalman->R);
	Kalman->X = Kalman->X + K * (NewData - Kalman->X);
	Kalman->P = (1 - K) * Kalman->P;
}