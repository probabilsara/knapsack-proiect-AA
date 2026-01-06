#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s input.txt output.txt\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    FILE *o = fopen(argv[2], "w");

    if (!f || !o)
    {
        perror("File error");
        return 1;
    }

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

    int *list = (int *)malloc(N * sizeof(int));
    int list_size = 0;

    int j = G;
    for (int i = N; i >= 1; i--)
        if (dp[i][j] != dp[i - 1][j])
        {
            list[list_size++] = i - 1;
            j -= w[i];
        }

    for (int i = 0; i < list_size - 1; i++)
    {
        for (int j = i + 1; j < list_size; j++)
        {
            if (list[i] > list[j])
            {
                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }

    fprintf(o, "%d\n", dp[N][G]);
    for (int i = 0; i < list_size; i++)
    {
        fprintf(o, list[i]);
    }

    free(list);

    for (int i = 0; i <= N; i++)
        free(dp[i]);

    free(dp);
    free(w);
    free(v);
    fclose(f);

    return 0;
}
