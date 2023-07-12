/*Implemente a função int mesmos_nos(TNoA *a1, TNoA *a2) que recebe ponteiros
para as raizes de duas árvores binárias teste se as árvores possuem os mesmos
nós (mesmo que em posições diferentes da árvore).*/

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

typedef struct lista
{
    int info;
    struct lista *prox;
} TLista;

// cria uma lista vazia
TLista *cria_lista(void)
{
    return NULL;
}

// insere ordenado na lista
TLista *insere_ordenado(TLista *lista, int valor)
{
    TLista *nova = (TLista *)malloc(sizeof(TLista));
    nova->info = valor;
    // vejo se a está vazia e insiro o elemento nela
    if (lista == NULL)
    {
        lista = nova;
        nova->prox = NULL;
    }
    else
    {
        // insere na primeira posição
        if (lista->info > valor)
        {
            nova->prox = lista;
            lista = nova;
        }
        // faz a busca
        else
        {
            TLista *anterior = lista;
            TLista *atual = lista->prox;

            while (atual && atual->info < valor)
            {
                anterior = atual;
                atual = atual->prox;
            }
            anterior->prox = nova;
            nova->prox = atual;
        }
    }
    return lista;
}

int compara_listas(TLista *l1, TLista *l2)
{
    if (l1 == NULL && l2 == NULL)
    {
        return 1;
    }
    if (l1 == NULL || l2 == NULL)
    {
        return 0;
    }
    if (l1->info == l2->info)
    {
        l1 = l1->prox;
        l2 = l2->prox;
        return compara_listas(l1, l2);
    }
    else
    {
        return 0;
    }
}

TLista *percorre(TNoA *no, TLista *li)
{
    if (no != NULL)
    {
        li = insere_ordenado(li, no->info);
        li = percorre(no->esq, li);
        li = percorre(no->dir, li);
    }
    return li;
}

void libera_lista(TLista *li)
{
    if (li != NULL)
    {
        TLista *prox = li->prox;
        free(li);
        libera_lista(prox);
    }
}

/* *Funcao deve retornar 1 caso as arvores tenham os mesmos nos (mesmo que em posicoes distintas), e 0 caso contrario
 */
int mesmos_nos(TNoA *a1, TNoA *a2)
{
    if (!a1 && !a2)
    {
        return 1;
    }
    if (!a1 || !a2)
    {
        return 0;
    }
    TLista *lista1 = cria_lista();
    TLista *lista2 = cria_lista();

    lista1 = percorre(a1, lista1);
    lista2 = percorre(a2, lista2);

    int resultado = compara_listas(lista1, lista2);
    libera_lista(lista1);
    libera_lista(lista2);
    return resultado;
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
    TNoA *a1 = NULL;
    TNoA *a2 = NULL;
    int tam;
    char entrada1[100];
    char entrada2[100];

    /* lê valores para criar a árvore 1
     * exemplo: FBC */
    scanf("%s", entrada1);
    tam = strlen(entrada1);
    a1 = criaArvore(entrada1, tam);

    /* le valores para criar a arvore 2 */
    scanf("%s", entrada2);
    tam = strlen(entrada2);
    a2 = criaArvore(entrada2, tam);

    printf("%d", mesmos_nos(a1, a2));
}