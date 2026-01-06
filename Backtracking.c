#include <stdio.h>
#include <stdlib.h>

int N, G;
int *w, *v;
int best_value = 0;
int *best_sol, *sol;
int best_size = 0;

void backtrack(int i, int cw, int cv, int size)
{
    if (cw > G)
        return;

    if (i == N)
    {
        if (cv > best_value)
        {
            best_value = cv;
            best_size = size;
            for (int j = 0; j < size; j++)
                best_sol[j] = sol[j];
        }
        return;
    }

    backtrack(i + 1, cw, cv, size);

    sol[size] = i;
    backtrack(i + 1, cw + w[i], cv + v[i], size + 1);
}

int main()
{
    FILE *f = fopen("tests/test1.txt", "r");

    fscanf(f, "%d %d", &N, &G);

    w = (int *)malloc(N * sizeof(int));
    v = (int *)malloc(N * sizeof(int));
    sol = (int *)malloc(N * sizeof(int));
    best_sol = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
        fscanf(f, "%d %d", &w[i], &v[i]);

    backtrack(0, 0, 0, 0);

    printf("%d\n", best_value);
    for (int i = 0; i < best_size; i++)
        printf("itemul de pe pozitia %d ", best_sol[i]);
    printf("\n");

    free(w);
    free(v);
    free(sol);
    free(best_sol);
    fclose(f);

    return 0;
}
