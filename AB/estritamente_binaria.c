// Função que verifica se uma árvore é estritamente binária,
// isto é, se os nós dessa árvore possuem ou zero ou dois filhos

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

int estbin(TAB *a)
{
    if (!a)
    {
        // Árvore vazia é considerada estritamente binária
        return 1;
    }
    else if (!a->esq && !a->dir)
    {
        // Nó folha é estritamente binário
        return 1;
    }
    else if (a->esq && a->dir)
    {
        // Verifica se ambos os filhos não são nulos
        return estbin(a->esq) && estbin(a->dir);
    }
    else
    {
        // Se chegou aqui, algum nó tem apenas um filho
        return 0;
    }
}
