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

int não_tem_mesma_cor(TGrafo *g)
{
    if (g->cor != g->primeiro_vizinho->cor)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void main()
{
    TGrafo *g = TG_inicializa();

    for (int i = 1; i < 10; i++)
    {
        g = TG_ins_no(g, i);
    }
    for (int i = 1; i < 9; i++)
    {
        TG_ins_aresta(g, i, i + 1);
    }

    int k = g->id;
    for (int k = 1; k < 10; k++)
    {
        if (k % 2 == 0)
        {
            g->cor = 0;
        }
        else
        {
            g->cor = 1;
        }
    }

    int i = g->id;
    int j = g->primeiro_vizinho->id_vizinho;
    for (i = 1; i < 10; i++)
    {
        j = i + 1;
        int cor = nao_tem_mesma_cor(g);
        if (cor == 0)
        {
            printf("Nó %d e nó %d são iguais\n", i, j);
        }
        if (cor == 1)
        {
            printf("Nó %d e nó %d são diferentes\n", i, j);
        }
    }
    TG_libera(g);
}