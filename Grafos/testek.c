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

int testek(TGrafo *g, int k){
    if(!g) return 1;
    TVizinho *v = g->primeiro_vizinho;
    int i = 0;
    while(v){
        v = v->prox;
        i++;
    }
    if(i == k) return testek(g->prox, k);
    else return 0;
}