#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int map[7][16] = { { 1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1 },
{ 1, 1,	1,	1,	1,	0,	1,	0,	0,	1,	0,	0,	1,	0,	0,	1 },
{ 1, 0,	0,	1,	0,	0,	1,	0,	0,	1,	0,	0,	1,	0,	0,	1},
{ 1, 0,	0,	1,	0,	0,	1,	0,	0,	1,	0,	0,	1,	0,	0,	1 },
{ 1, 1,	0,	1,	1,	0,	1,	0,	0,	0,	0,	1,	0,	0,	0,	1 },
{ 1, 1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1 },
{ 1, 1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	1 } };
int Des_I;
int Des_J;
int Src_I;
int Src_J;
int min = 0x7fffff;
struct st
{
    int i, j;
};
struct st route[100000];
int ans[7][16];
int chk[7][16];
void DFS(int I, int J, int n)
{
    if (I > 6 || I < 0 || J > 15 || J < 0) return;
    if (n > min) return;

    chk[I][J] = 1;
    route[n].i = I;
    route[n].j = J;

    if (I == Des_I && J == Des_J)
    {
        memset(ans, 0, sizeof(ans));
        min = n;
        for (int i = 0; i <= n; i++)
        {
            ans[route[i].i][route[i].j] = 1;
        }
        return;
    }


    if (map[I - 1][J] == 0 && chk[I - 1][J] == 0)
    {
        DFS(I - 1, J, n + 1);
        chk[I - 1][J] = 0;
        route[n + 1].i = 0;
        route[n + 1].j = 0;
    }
    if (map[I][J + 1] == 0 && chk[I][J + 1] == 0)
    {
        DFS(I, J + 1, n + 1);
        chk[I][J + 1] = 0;
        route[n + 1].i = 0;
        route[n + 1].j = 0;
    }
    if (map[I + 1][J] == 0 && chk[I + 1][J] == 0)
    {
        DFS(I + 1, J, n + 1);
        chk[I + 1][J] = 0;
        route[n + 1].i = 0;
        route[n + 1].j = 0;
    }
    if (map[I][J - 1] == 0 && chk[I][J - 1] == 0)
    {
        DFS(I, J - 1, n + 1);
        chk[I][J - 1] = 0;
        route[n + 1].i = 0;
        route[n + 1].j = 0;
    }
}

void PRINTANS(void)
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
    printf("%d", min);
}

int main(void)
{
    scanf("%d %d", &Des_I, &Des_J);
    scanf("%d %d", &Src_I, &Src_J);
    DFS(Src_I, Src_J, 0);
    PRINTANS();
    return 0;
}
