//Função que encontra o menor elemento da ávore

#include <stdio.h>
#include <stdlib.h>

typedef struct ab
{
    int info;
    struct ab *esq, *dir;
} TABB;

TABB *menor(TABB *a)
{
    if (!a)
    {
        return NULL;
    }

    TABB *menor_no = a;
    while (menor_no->esq)
    {
        menor_no = menor_no->esq;
    }
    return menor_no;
}
