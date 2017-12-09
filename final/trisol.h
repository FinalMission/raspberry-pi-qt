#ifndef _TRISOL_
#define _TRISOL_

typedef struct {
    double a, b, k;
}_circle;

typedef struct {
    double a, b, k;
}_line;

typedef struct {
    double x, y;
}_dot;

void _solve_line(_circle c1, _circle c2, _line * l);
void _solve_dot(_line l1, _line l2, _dot * d);
void _solve_position(_circle * circle, _dot * ans);

#endif
