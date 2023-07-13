#include <stdio.h>
#include <stdlib.h>

typedef struct noA
{
    char info;
    int cor;
    struct noA *esq;
    struct noA *dir;
} TNoA;

TNoA *inicializa(void);
void imprime(TNoA *nodo, int tab);
TNoA *criaNo(char ch);

typedef struct lista
{
    char info;
    struct lista *prox;
} TLista;

TLista *cria_lista(void);
TLista *insere_inicio(TLista *li, char i);
TLista *insere_ordenado(TLista *li, int valor);
TLista *percorre(TNoA *a, TLista *li);
int compara_listas(TLista *l1, TLista *l2);
void libera_lista(TLista *li);

//GRAFO
typedef struct viz{
    int id_vizinho;
    struct viz *prox;
} TVizinho;
typedef struct grafo{
    int id;
    int cor;
    struct grafo *prox;
    TVizinho *primeiro_vizinho;
} TGrafo;

int na(TGrafo *g);
int nv(TGrafo *g);
int iguais(TGrafo *g1, TGrafo *g2);
int nao_tem_mesma_cor(TGrafo *g);

