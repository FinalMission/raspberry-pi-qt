#include <stdio.h>
#include <stdlib.h>
#include "trisol.h"
#include "kfsol.h"
#pragma warning (disable:4996)



int main(int argc, char ** argv) {

	//trisol.c
	//_circle c[3] = { { 0, 0, 1 }, { 1, 4, 1 }, { 2, 0, 1 } };
	//_dot d;
	//_solve_position(c, &d);
	//printf("x = %.2f\ny = %.2f", d.x, d.y);
	
	// kfsol.c
	double sample[100];
	for (int i = 0; i < 100; i++) 
		//sample[i] = (-10 + rand() % 201/10.0 );
		sample[i] = i>50?50:i;

	SKalman1D kalman;
	kalman.X = 0;
	kalman.Q = 10;
	kalman.P = 10;
	kalman.R = 200;

	printf("now position = %.2f \n", kalman.X);
	for (int i = 0; i < 100; i++) {
		KalmanPredictUpdate1D(&kalman, sample[i]);
		printf("now pos = %6.2f, real pos = %6.2f \n", kalman.X, sample[i]);
	}
	
	return 0;
}