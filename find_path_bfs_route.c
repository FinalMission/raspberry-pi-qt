#define H_LEN 75
#define V_LEN 35
#define QUE 2000

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

void CheckPath(void) {
	for (;;) {
		if (last == -1) return;
		ans[route[last].i][route[last].j] = 1;
		last = route[last].parentqnum;
	}
}

int main(void) {
	int i, j;

	for (i = 0; i < V_LEN; i++)
		for (j = 0; j < H_LEN; j++)
			scanf("%1d", &map[i][j]);

	Src_I = 12;
	Src_J = 10;
	Des_I = 10;
	Des_J = 20;
	FindDst();
	CheckPath();
	return 0;
}
