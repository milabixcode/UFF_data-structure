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