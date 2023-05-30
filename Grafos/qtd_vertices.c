// Função que retorna a quantidade de vértices

#include <stdio.h>

typedef struct viz
{
    int id_vizinho;
    struct viz *prox;
} TVizinho;

typedef struct grafo
{
    int id;
    struct grafo *prox;
    TVizinho *primeiro_vizinho;
} TGrafo;

int nv(TGrafo *g)
{

    int qtd = 1;
    while (g)
    {
        g = g->prox;
        qtd += 1;
    }
    return qtd;
}
