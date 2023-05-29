#include <stdio.h>
#include <stdlib.h>

typedef struct a
{
    int info;
    struct a *esq, *dir;
} TAB;

int igual(TAB *a1, TAB *a2)
{
    if (!a1 && !a2)
    {
        return 1;
    }
    if (!a1 || !a2)
    {
        return 0;
    }

    if (a1->info == a2->info)
    {
        if (igual(a1->esq, a2->esq))
        {
            if (igual(a1->dir, a2->dir))
            {
                return 1;
            }
        }
    }
    return 0;
}