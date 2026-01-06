#include <stdio.h>

int N, G;
int w[1000], v[1000];
int dp[1001][1001];

int main()
{
    scanf("%d %d", &N, &G);
    for (int i = 1; i <= N; i++)
        scanf("%d %d", &w[i], &v[i]);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= G; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i])
            {
                int val = dp[i - 1][j - w[i]] + v[i];
                if (val > dp[i][j])
                    dp[i][j] = val;
            }
        }
    }

    printf("%d\n", dp[N][G]);

    // reconstructie solutie
    int j = G;
    for (int i = N; i >= 1; i--)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            printf("%d ", i - 1);
            j -= w[i];
        }
    }
    printf("\n");

    return 0;
}
