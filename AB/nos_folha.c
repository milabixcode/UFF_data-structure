//Retorna a quantidade de nós folha

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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

TAB *criaArvore(char entrada[100], int tamanho)
{
    char novaEntrada[100];
    int i, j;
    TAB *novo;
    novo = NULL;
    if ((tamanho > 0) && (entrada[0] != '*'))
    {
        novo = (TAB *)malloc(sizeof(TAB));
        novo->info = entrada[0];
        tamanho = tamanho / 2;

        // divide a entrada em duas partes e chama a função criaArvore recursivamente
        i = 1; // inicio da subarvore esquerda na string entrada
        j = 0; // cursor da nova string de entrada que conterá apenas a subárvore desejada
        while (i <= tamanho)
        {
            novaEntrada[j] = entrada[i];
            i++;
            j++;
        }
        novaEntrada[i] = '\0';
        novo->esq = criaArvore(novaEntrada, tamanho);

        i = tamanho + 1; // inicio da subarvore direita na string entrada
        j = 0;           // cursor da nova string de entrada que conterá apenas a subárvore desejada
        while (i <= tamanho * 2)
        {
            novaEntrada[j] = entrada[i];
            i++;
            j++;
        }
        novaEntrada[i] = '\0';
        novo->dir = criaArvore(novaEntrada, tamanho);
    }
    return novo;
}

int nf(TAB *a)
{
    if (!a)
    {
        return 0;
    }

    if (!a->esq && !a->dir)
    {
        return 1;
    }

    int nos = 0;
    if (a->esq)
    {
        nos =+ nf(a->esq);
    }
    if (a->dir)
    {
        nos =+ nf(a->dir);
    }
    return nos;
}

int main(void)
{
    /* A função main lê os dados de entrada, cria a árvore e chama a função solicitada no exercício
     * depois imprime a árvore resultante
     * Ela NÃO DEVE SER MODIFICADA
     * */
    TAB *raiz = NULL;
    int tam;
    char entrada[100];
    int num_nos_folha;

    /* lê valores para criar a árvore
     * exemplo: FBC */
    scanf("%s", entrada);
    tam = strlen(entrada);

    raiz = criaArvore(entrada, tam);
    num_nos_folha = nf(raiz);
    printf("%d", num_nos_folha);
}