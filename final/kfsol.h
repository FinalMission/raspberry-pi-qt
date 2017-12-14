#ifndef _KFSOL_
#define _KFSOL_

typedef struct{
    double	X;  // 상태 행렬
    double	Q;  //~ 센서 노이즈 공분산 상수
    double	P;  // 상태 공분산 행렬 // 오차 공분산
    double	R;  //~ 측정 공분산 행렬 // R이 Q보다 큼
}SKalman1D;

#endif
