//Função que encontra o maior elemento da árvore

#include <stdio.h>
#include <stdlib.h>

typedef struct ab
{
    int info;
    struct ab *esq, *dir;
} TABB;

TABB *maior(TABB *a)
{
    if (!a)
    {
        return NULL;
    }

    TABB *maior_no = a;
    while (maior_no->dir)
    {
        maior_no = maior_no->dir;
    }
    return maior_no;
}
