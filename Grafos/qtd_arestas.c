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


// Função que retorna a quantidade de arestas
int na(TGrafo *g)
{
    //contador começa a 0
    int contador_vizinhos = 0;

    //guardo o primeiro vizinho em uma variável
    TVizinho *proximo = g->primeiro_vizinho;
    //enquanto eu tiver um proximo
    //somo 1 no contador
    //e vou para o proximo
    while (proximo)
    {
        contador_vizinhos += 1;
        proximo = proximo->prox;
    } 

    //se o grafo tiver o proximo
    if (g->prox)
    {
        return contador_vizinhos + na(g->prox);
    }

    return contador_vizinhos;
}
