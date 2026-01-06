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

    Item *items = (Item *)malloc(N * sizeof(Item));
    for (int i = 0; i < N; i++)
    {
        fscanf(f, "%d %d", &items[i].g, &items[i].v);
        items[i].idx = i;
        items[i].ratio = (double)items[i].v / items[i].g;
    }

    qsort(items, N, sizeof(Item), cmp);

    int total_g = 0, total_v = 0;

        int *list = (int *)malloc(N * sizeof(int));
    int list_size = 0;

    for (int i = 0; i < N; i++)
    {
        if (total_g + items[i].g <= G)
        {
            total_g += items[i].g;
            total_v += items[i].v;
            list[list_size++] = items[i].idx;
        }
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

    fprintf(o, "%d\n", total_v);
    for (int i = 0; i < list_size; i++)
    {
        fprintf(o, list[i]);
    }

    free(items);
    free(list);
    fclose(f);
    fclose(o);
    return 0;
}
