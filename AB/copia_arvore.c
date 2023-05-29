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

TAB *copia(TAB *a)
{
    // caso base
    if (!a)
    {
        return NULL;
    }
    // função recursiva
    TAB *arvore_copiada = cria(a->info, copia(a->esq), copia(a->dir));
    return arvore_copiada;
}

void imprime_simetrico(TAB *a)
{
  if(a){
    imprime_simetrico(a->esq);
    printf("%d ", a->info);
    imprime_simetrico(a->dir);
  }
}

int main()
{
    TAB *arvore, *arvore_copiada;
    int no_arvore = 5;
    arvore = inicializa();
    arvore = cria(no_arvore, NULL, NULL);
    arvore_copiada = copia(arvore);
    imprime_simetrico(arvore_copiada);
}