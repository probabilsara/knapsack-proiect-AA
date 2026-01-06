#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int g, v, idx;
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

    FILE *f = fopen("tests/test1.txt", "r");
    int N, G;
    fscanf(f, "%d %d", &N, &G);

    Item *items = (Item *)malloc(N * sizeof(Item));
    for (int i = 0; i < N; i++)
    {
        fscanf(f, "%d %d", &items[i].g, &items[i].v);
        items[i].idx = i;
        items[i].ratio = (double)items[i].v / items[i].g;
    }

    qsort(items, N, sizeof(Item), cmp);

    int total_g = 0, total_v = 0;

    for (int i = 0; i < N; i++)
    {
        if (total_g + items[i].g <= G)
        {
            total_g += items[i].g;
            total_v += items[i].v;
            printf("itemul de pe pozitia\n %d  ", items[i].idx);
        }
    }

    printf("\nvaloarea totala: %d\n", total_v);

    free(items);
    fclose(f);
    return 0;
}
