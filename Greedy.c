#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int w, v, idx;
    double ratio;
} Item;

int cmp(const void *a, const void *b)
{
    Item *x = (Item *)a;
    Item *y = (Item *)b;
    if (x->ratio < y->ratio)
        return 1;
    if (x->ratio > y->ratio)
        return -1;
    return 0;
}

int main()
{
    int N, G;
    scanf("%d %d", &N, &G);

    Item items[1000];
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &items[i].w, &items[i].v);
        items[i].idx = i;
        items[i].ratio = (double)items[i].v / items[i].w;
    }

    qsort(items, N, sizeof(Item), cmp);

    int total_w = 0, total_v = 0;
    printf("Solutie greedy:\n");

    for (int i = 0; i < N; i++)
    {
        if (total_w + items[i].w <= G)
        {
            total_w += items[i].w;
            total_v += items[i].v;
            printf("%d ", items[i].idx);
        }
    }

    printf("\n%d\n", total_v);
    return 0;
}
