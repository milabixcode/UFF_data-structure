#include <stdio.h>
#include <stdlib.h>

/*typedef struct ab
{
    int info;
    struct ab *esq, *dir;
} TAB;

TAB *TAB_inicializa(void)
{
    return NULL;
}

TAB *TAB_cria(int raiz, TAB *esq, TAB *dir)
{
    TAB *novo = (TAB *)malloc(sizeof(TAB));
    novo->info = raiz;
    novo->esq = esq;
    novo->dir = dir;
    return novo;
}

TAB *TAB_clona(TAB *a)
{
    if (!a)
    {
        return NULL;
    }
    TAB *arvore_clonada = TAB_cria(a->info, TAB_clona(a->esq), TAB_clona(a->dir));
    return arvore_clonada;
}

void TAB_imp_sim(TAB *a)
{
    if (a)
    {
        TAB_imp_sim(a->esq);
        printf("%d ", a->info);
        TAB_imp_sim(a->dir);
    }
}

int main()
{
    TAB *arvore, *arvore_clonada;
    int no_arvore = 5;
    arvore = TAB_inicializa();
    arvore = TAB_cria(no_arvore, NULL, NULL);
    arvore_clonada = TAB_clona(arvore);
    TAB_imp_sim(arvore_clonada);
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct noA
{
    char info;
    struct noA *esq;
    struct noA *dir;
} TNoA;

TNoA* copia(TNoA *a){
    if(!a){
        return NULL;
    }
    TNoA* arvore_copiada = (TNoA*)malloc(sizeof(TNoA));
    arvore_copiada->esq = copia(arvore_copiada->esq);
    arvore_copiada->dir = copia(arvore_copiada->dir);

    return a;
}

void imprime(TNoA *nodo, int tab)
{
    for (int i = 0; i < tab; i++)
    {
        printf("-");
    }
    if (nodo != NULL)
    {
        printf("%c\n", nodo->info);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    }
    else
        printf("vazio");
}

void imprimeProfundidade(TNoA *nodo, int altura)
{
    altura = altura - 1;
    if (nodo != NULL)
    {
        printf("%c", nodo->info);
        if (altura > 0)
        {
            imprimeProfundidade(nodo->esq, altura);
            imprimeProfundidade(nodo->dir, altura);
        }
    }
    else
    {
        printf("*");
        // Trata caso de subarvore NULL em nível menor que altura da árvore
        if (altura > 0)
        {
            imprimeProfundidade(NULL, altura);
            imprimeProfundidade(NULL, altura);
        }
    }
}

TNoA *criaArvore(char entrada[100], int tamanho)
{
    char novaEntrada[100];
    int i, j;
    TNoA *novo;
    novo = NULL;
    if ((tamanho > 0) && (entrada[0] != '*'))
    {
        novo = (TNoA *)malloc(sizeof(TNoA));
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

int main(void)
{
    /* A função main lê os dados de entrada, cria as árvores e chama a função solicitada no exercício
     * depois imprime o resultado
     * Ela NÃO DEVE SER MODIFICADA
     * */
    TNoA *a = NULL;
    TNoA *arvore_clonada = NULL;
    
    int tam;
    char entrada[100];
    
    /* lê valores para criar a árvore 1
     * exemplo: FBC */
    scanf("%s", entrada);
    tam = strlen(entrada);
    a = criaArvore(entrada, tam);
    arvore_clonada = copia(a);

    imprimeProfundidade(arvore_clonada, tam);
}