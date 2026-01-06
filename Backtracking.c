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
    fscanf(f, "%d %d", &N, &G);

    w = (int *)malloc(N * sizeof(int));
    v = (int *)malloc(N * sizeof(int));
    sol = (int *)malloc(N * sizeof(int));
    best_sol = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
        fscanf(f, "%d %d", &w[i], &v[i]);

    backtrack(0, 0, 0, 0);

    for (int i = 0; i < best_size - 1; i++)
    {
        for (int j = i + 1; j < best_size; j++)
        {
            if (best_sol[i] > best_sol[j])
            {
                int temp = best_sol[i];
                best_sol[i] = best_sol[j];
                best_sol[j] = temp;
            }
        }
    }

    fprintf(o, "%d\n", best_value);
    for (int i = 0; i < best_size; i++)
        fprintf(o, "%d ", best_sol[i]);

    free(w);
    free(v);
    free(sol);
    free(best_sol);
    fclose(f);
    fclose(o);

    return 0;
}
