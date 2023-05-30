#include <stdio.h>

typedef struct viz
{
    int id_vizinho;
    int cor;
    struct viz *prox;
} TVizinho;

typedef struct grafo
{
    int id;
    int cor;
    struct grafo *prox;
    TVizinho *primeiro_vizinho;
} TGrafo;

int testek(TGrafo *g, int k)
{
    if (!g)
    {
        return 0; 
    }


}