#include<cstdio>

int dp[1010][20][20], n;

inline int max3(int a, int b, int c)
{
    int ret = a;
    if (ret < b) ret = b;
    if (ret < c) ret = c;
    return ret;
}

inline int max2(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int white, black, i, j;
    while (scanf("%d%d", &white, &black) != EOF)
    {
        n++;
        for (i = 1; i <= 15; i++)
        {
            dp[n][i][0] = max2(dp[n - 1][i - 1][0] + white, dp[n - 1][i][0]);
            dp[n][0][i] = max2(dp[n - 1][0][i - 1] + black, dp[n - 1][0][i]);
            for (j = 1; j <= 15; j++)
                dp[n][i][j] = max3(dp[n - 1][i - 1][j] + white, dp[n - 1][i][j - 1] + black, dp[n - 1][i][j]);
        }
    }
    printf("%d\n", dp[n][15][15]);
    return 0;
}