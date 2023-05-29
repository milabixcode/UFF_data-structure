//Retorna quantidade de nós internos

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

int ni(TAB *a)
{
    if (!a)
    {
        return 0;
    }
    else
    {
        int contador = 1;
        contador += ni(a->esq);
        contador += ni(a->dir);
        return contador;
    }
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
    int numero_nos_internos;

    /* lê valores para criar a árvore
     * exemplo: FBC */
    scanf("%s", entrada);
    tam = strlen(entrada);

    raiz = criaArvore(entrada, tam);
    numero_nos_internos = ni(raiz);
    printf("%d", numero_nos_internos);
}