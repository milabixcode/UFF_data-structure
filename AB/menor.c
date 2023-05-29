#include <stdio.h>
#include <stdlib.h>

typedef struct a
{
    int info;
    struct a *esq, *dir;
} TAB;

TAB *menor(TAB *a)
{
    if (!a)
    {
        return NULL;
    }

    TAB *esq = menor(a->esq);
    TAB *dir = menor(a->dir);

    TAB *menor = a;

    if (esq)
    {
        if (esq->info < menor->info)
        {
            menor = esq;
        }
    }
    if (dir)
    {
        if (dir->info < menor->info)
        {
            menor = dir;
        }
    }
    return menor;
}