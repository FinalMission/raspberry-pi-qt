#ifndef _KFSOL_
#define _KFSOL_

typedef struct{
	double	X;  // ���� ���
	double	Q;  //~ ���� ������ ���л� ���
	double	P;  // ���� ���л� ��� // ���� ���л�
	double	R;  //~ ���� ���л� ��� // R�� Q���� ŭ
}SKalman1D;

void KalmanPredictUpdate1D(SKalman1D *kalman, double NewData);

#endif