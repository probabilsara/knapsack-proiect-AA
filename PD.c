#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    FILE *f = fopen("tests/test1.txt", "r");

    int N, G;
    fscanf(f, "%d %d", &N, &G);

    int *w = (int *)malloc((N + 1) * sizeof(int));
    int *v = (int *)malloc((N + 1) * sizeof(int));

    for (int i = 1; i <= N; i++)
        fscanf(f, "%d %d", &w[i], &v[i]);

    int **dp = (int **)malloc((N + 1) * sizeof(int *));
    for (int i = 0; i <= N; i++)
        dp[i] = (int *)calloc(G + 1, sizeof(int));

    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= G; j++)
            if (j >= w[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            else
                dp[i][j] = dp[i - 1][j];

    printf("%d\n", dp[N][G]);

    int j = G;
    for (int i = N; i >= 1; i--)
        if (dp[i][j] != dp[i - 1][j])
        {
            printf("itemul de pe pozitia %d ", i - 1);
            j -= w[i];
        }

    printf("\n");

    for (int i = 0; i <= N; i++)
        free(dp[i]);

    free(dp);
    free(w);
    free(v);
    fclose(f);

    return 0;
}
