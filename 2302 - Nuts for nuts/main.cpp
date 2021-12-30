#include <stdio.h>
#include <string.h>
#define INF 0x3F3F3F3F
#define MAX 16
int dp[1<<MAX][MAX+1];

int xx, yy, i, j;
int x[21], y[21], m[21][21];
int total, tests, nuts;
char mas[21][21];

int max(int i, int j)
{
    return (i > j) ? i : j;
}

int min(int i, int j)
{
    return (i < j) ? i : j;
}

int abs(int x)
{
    return (x > 0) ? x : -x;
}

int solve(int mask, int last)
{
    int &res = dp[mask][last];
    if(res == INF)
    {
        mask ^= (1 << last);
        for(int i = 1; i < nuts; ++i)
            if(mask & (1 << i)) res = min(res,solve(mask,i) + m[i][last]);
    }
    return res;
}

int main(void)
{
    //freopen("2302.in","r",stdin);
    while(scanf("%d %d\n",&xx,&yy) == 2)
    {
        for(i = 0; i < xx; i++) gets(mas[i]);

        nuts = 1;
        for(i = 0; i < xx; i++)
            for(j = 0; j < yy; j++)
                if (mas[i][j] == 'L')
                {
                    x[0] = i; y[0] = j;
                } else
                if (mas[i][j] == '#')
                {
                    x[nuts] = i; y[nuts++] = j;
                }

        if (nuts == 1)
        {
            printf("0\n"); continue;
        }

        memset(m,0x3F,sizeof(m));
        for(i = 0; i < nuts - 1; i++)
            for(j = i + 1; j < nuts; j++)
                m[i][j] = m[j][i] = max(abs(x[i] - x[j]), abs(y[i] - y[j]));

        memset(dp,0x3F,sizeof(dp));
        dp[1][0] = 0; total = INF;
        for(i = 1; i < nuts; i++) dp[1 | (1 << i)][i] = m[0][i];

        for(i = 1; i < nuts; i++)
            total = min(total, solve((1 << nuts) - 1,i) + m[i][0]);

        printf("%d\n",total);
    }
    return 0;
}
