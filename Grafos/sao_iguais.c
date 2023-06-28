// Função para checar se dois grafos são iguais

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

int sao_iguais(TGrafo *g1, TGrafo *g2)
{
    if (!g1 || !g2)
    {
        return 0;
    }

    if (!g1 && !g2)
    {
        return 1;
    }

    TVizinho *v1 = g1->primeiro_vizinho;
    TVizinho *v2 = g2->primeiro_vizinho;

    if (g1->id == g2->id)
    {
        while (v1 && v2)
        {
            if (v1->id_vizinho == v2->id_vizinho)
            {
                v1 = v1->prox;
                v2 = v2->prox;
            }
            else
            {
                return 0;
            }
        }
        return sao_iguais(g1->prox, g2->prox);
    }
}
