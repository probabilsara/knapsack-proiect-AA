#include <stdio.h>

int N, G;
int w[100], v[100];
int best_value = 0;
int best_sol[100], sol[100];
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

    // nu luam obiectul i
    backtrack(i + 1, cw, cv, size);

    // luam obiectul i
    sol[size] = i;
    backtrack(i + 1, cw + w[i], cv + v[i], size + 1);
}

int main()
{
    scanf("%d %d", &N, &G);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &w[i], &v[i]);

    backtrack(0, 0, 0, 0);

    printf("%d\n", best_value);
    for (int i = 0; i < best_size; i++)
        printf("%d ", best_sol[i]);
    printf("\n");

    return 0;
}
