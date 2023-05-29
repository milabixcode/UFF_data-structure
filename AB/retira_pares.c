#include <stdio.h>
#include <stdlib.h>

typedef struct a
{
    int info;
    struct a *esq, *dir;
} TAB;

TAB *inicializa(void)
{
    return NULL;
}

TAB *cria(int info, TAB *esq, TAB *dir)
{
    TAB *novo = (TAB *)malloc(sizeof(TAB));

    novo->info = info;
    novo->esq = esq;
    novo->dir = dir;

    return novo;
}
void imprime_simetrico(TAB *a)
{
    if (a)
    {
        imprime_simetrico(a->esq);
        printf("%d ", a->info);
        imprime_simetrico(a->dir);
    }
}

TAB *retira(TAB *arv, int x)
{
    if (!arv)
    {
        return NULL;
    }

    if (arv->info != x)
    {
        arv->esq = retira(arv->esq, x);
        arv->dir = retira(arv->dir, x);
    }

    if (arv->info == x)
    {
        if (!arv->esq && !arv->dir)
        {
            free(arv);
            arv = NULL;
        }
        else if (!arv->esq || !arv->dir)
        {
            TAB *p;
            if (arv->esq)
            {
                p = arv->esq;
                free(arv);
                arv = p;
            }
            else
            {
                p = arv->dir;
                free(arv);
                arv = p;
            }
        }
        else
        {
            TAB *p, *q;
            p = arv->esq;
            while (p->dir)
            {
                p = p->dir;
            }
            q = arv->esq;
            p->dir = arv->dir;
            free(arv);
            arv = q;
        }
    }
    return arv;
}

TAB *retira_pares(TAB *arv)
{
    if (!arv)
    {
        return NULL;
    }

    TAB *esquerda = retira_pares(arv->esq);
    TAB *direita = retira_pares(arv->dir);
    
    arv->esq = esquerda;
    arv->dir = direita;

    if (arv->info % 2 == 0)
    {
        arv = retira(arv, arv->info);
    }
    return arv;
}

int main(void)
{
    TAB *arv = cria(100,
                    cria(50,
                         cria(20,
                              cria(10, NULL, NULL),
                              cria(25,
                                   NULL,
                                   cria(30, NULL, NULL))),
                         cria(40, cria(45, NULL, NULL), NULL)),
                    NULL);

    imprime_simetrico(arv);
    printf("\n");
    arv = retira(arv, 50);
    imprime_simetrico(arv);
    printf("\n");
    arv = retira_pares(arv);
    imprime_simetrico(arv);
    printf("\n");
}