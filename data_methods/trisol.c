
#include "trisol.h"

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