// Função para testar se o grafo é completo

#include <stdio.h>
#include <stdlib.h>

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

int num_nos(TGrafo *g)
{
    if (!g)
    {
        return 0;
    }
    int numero = 1 + num_nos(g->prox);
    return numero;
}

int contador_grafo(TGrafo *g, int tam, int *contador)
{
    if (!g)
    {
        if ((*contador) == tam)
        {
            return 1;
        }

        else
        {
            return 0;
        }
    }
    int aux = 0;
    TVizinho *vizinho = g->primeiro_vizinho;
    while (vizinho)
    {
        aux++;
        vizinho = vizinho->prox;
    }
    if (aux == (tam - 1))
    {
        ++(*contador);
        return contador_grafo(g->prox, tam, contador);
    }
    return 0;
}

int completo(TGrafo *g)
{
    if (!g)
    {
        return 0;
    }

    int contador = 0, tam = num_nos(g);
    return contador_grafo(g, tam, &contador);
}