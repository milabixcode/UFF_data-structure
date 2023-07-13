#include "arvore-binaria.h"

TLista *cria_lista(void)
{
    return NULL;
}

TLista *insere_inicio(TLista *li, char i)
{
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = li;
    return novo;
}

TLista *insere_ordenado(TLista *li, int valor)
{
    // aloco memoria
    TLista *nova = (TLista *)malloc(sizeof(TLista));
    // atribuo valor ao elemento da lista
    nova->info = valor;
    // Lista está vazia
    // insiro elemento e o proximo é nulo
    if (li == NULL)
    {
        li = nova;
        nova->prox = NULL;
    }
    // se lista não está vazia
    else
    {
        // se ele for menor que o primeiro elemento da lista
        // insere na primeira posição
        if (li->info > valor)
        {
            nova->prox = li;
            li = nova;
        }
        // se não for menor que o primeiro elemento da lista
        // preciso procurar o lugar dele na lista
        else
        {
            TLista *anterior = li;
            TLista *atual = li->prox;

            while (atual && atual->prox < valor)
            {
                anterior = atual;
                atual = atual->prox;
            }
            anterior->prox = nova;
            nova->prox = atual;
        }
    }
    return li;
}

TLista *percorre(TNoA *a, TLista *li)
{
    if (a != NULL)
    {
        li = insere_ordenado(li, a->info);
        li = percorre(a->esq, li);
        li = percorre(a->dir, li);
    }
    return li;
}

int compara_listas(TLista *l1, TLista *l2)
{
    // se ambas forem nulas são iguais
    if (l1 == NULL && l2 == NULL)
    {
        return 1;
    }
    // se somente uma delas for nula, são diferentes
    if (l1 == NULL || l2 == NULL)
    {
        return 0;
    }
    // se as infos sao iguais, vai andando na lista e comparando recursivamente
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

void libera_lista(TLista *li)
{
    if (li != NULL)
    {
        TLista *prox = li->prox;
        free(li);
        libera_lista(prox);
    }
}

TNoA *inicializa(void)
{
    return NULL;
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

TNoA *criaNo(char ch)
{
    TNoA *novo;
    novo = (TNoA *)malloc(sizeof(TNoA));
    novo->info = ch;
    novo->cor = 0;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}
// ARVORE BINARIA
//  Questao 01
TNoA *copia(TNoA *a)
{
    // caso base
    if (!a)
    {
        return NULL;
    }
    // aloco memoria para o no
    TNoA *raiz = (TNoA *)malloc(sizeof(TNoA));
    // copio a informacao
    raiz->info = a->info;
    // recursivamente copio esq e dir
    raiz->esq = copia(a->esq);
    raiz->dir = copia(a->dir);

    return raiz;
}
// Questao 02

TNoA *espelho(TNoA *a)
{
    if (!a)
    {
        return NULL;
    }

    TNoA *raiz = (TNoA *)malloc(sizeof(TNoA));

    raiz->info = a->info;

    raiz->dir = espelho(a->esq);
    raiz->esq = espelho(a->dir);

    return raiz;
}

// Questao 03
TNoA *maior(TNoA *a)
{
    if (!a)
    {
        return NULL;
    }

    TNoA *no_maior = a;
    TNoA *no_maior_esq;
    TNoA *no_maior_dir;

    no_maior_esq = maior(a->esq);
    no_maior_dir = maior(a->dir);

    if (no_maior_esq && no_maior_esq->info > no_maior->info)
    {
        no_maior = no_maior_esq;
    }
    if (no_maior_dir && no_maior_dir->info > no_maior->info)
    {
        no_maior = no_maior_dir;
    }
    return no_maior;
}

// Questao 04
TNoA *menor(TNoA *a)
{
    if (!a)
    {
        return NULL;
    }
    TNoA *no_menor = a;
    TNoA *no_menor_esq = menor(a->esq);
    TNoA *no_menor_dir = menor(a->dir);

    if (no_menor_esq && no_menor_esq->info < no_menor->info)
    {
        no_menor = no_menor_esq;
    }
    if (no_menor_dir && no_menor_dir->info < no_menor->info)
    {
        no_menor = no_menor_dir;
    }
    return no_menor;
}

// Questao 05
// Dadas duas arvores retorna 1 se são iguais e 0, caso contrario

int igual(TNoA *a1, TNoA *a2)
{
    if (!a1 && !a2)
    {
        return 1;
    }
    if (!a1 || !a2)
    {
        return 0;
    }

    // if (a1->info != a2->info)
    // {
    //     return 0;
    // }

    // if (!igual(a1->esq, a2->esq)){
    //     return 0;
    // }

    // if (!igual(a1->dir, a2->dir)){
    //     return 0;
    // }

    // return 1;

    if (a1->info == a2->info && igual(a1->esq, a2->esq) && igual(a1->dir, a2->dir))
    {
        return 1;
    }

    return 0;
}

TNoA *retira_pares(TNoA *a)
{
    if (!a)
    {
        return NULL;
    }

    a->esq = retira_pares(a->esq);
    a->dir = retira_pares(a->dir);

    // Caso NO FOLHA
    if (!a->esq && !a->dir && a->info % 2 == 0)
    {
        free(a);
        return NULL;
    }
    // CASO NO COM UM FILHO
    if (a->esq || a->dir && a->info % 2 == 0)
    {
        if (!a->esq)
        {
            TNoA *dir = a->dir;
            free(a);
            return dir;
        }
        if (!a->dir)
        {
            TNoA *esq = a->esq;
            free(a);
            return esq;
        }
    }
    // CASO NO COM DOIS FILHOS
    else
    {
        TNoA *atual = a->esq;
        TNoA *anterior = a;
        while (atual->dir)
        {
            anterior = atual;
            atual = atual->dir;
        }
        a->info = atual->info;
        free(atual);
        anterior->dir = NULL;

        return a;
    };
}

// Questao 07
// Nós são coloridos de vermelho e preto
// Nó pai NUNCA pode ter a mesma cor de seus filhos

#define SEM_COR 0
#define PRETO 1
#define VERMELHO 2

void colore(TNoA *a)
{
    if (!a)
    {
        return;
    }
    if (a->cor == SEM_COR)
    {
        a->cor = PRETO;
    }
    int cor_filhos;

    if (a->cor == PRETO)
    {
        cor_filhos = VERMELHO;
    }
    else
    {
        cor_filhos = PRETO;
    }

    if (a->esq)
    {
        a->esq->cor = cor_filhos;
    }

    if (a->dir)
    {
        a->dir->cor = cor_filhos;
    }

    colore(a->esq);
    colore(a->dir);
}

// Questao 8
// Retorna quantidade de nós internos

int ni(TNoA *a)
{
    // se arvore vazia
    if (!a)
    {
        return 0;
    }
    // se nó é folha
    if (!a->esq && !a->dir)
    {
        return 0;
    }

    int qtd_esq = ni(a->esq);
    int qtd_dir = ni(a->dir);

    return qtd_esq + qtd_dir + 1;
}

// Questao 9
// Retorna quantidade de nós folhas

int nf(TNoA *a)
{
    if (!a)
    {
        return 0;
    }
    if (!a->esq && !a->dir)
    {
        return 1;
    }
    int qtd_esq = nf(a->esq);
    int qtd_dir = nf(a->dir);

    return qtd_dir + qtd_esq;
}

// Questão 10
// Testar se árvore é zigue zague: tds nósinternmos possuem exatamente uma sub-árvore vazia

int zz(TNoA *a)
{
    if (!a)
    {
        return 1;
    }

    if (a->esq && a->dir)
    {
        return 0;
    }

    if (a->esq || a->dir)
    {
        return (zz(a->esq) && zz(a->dir));
    }
    return 1;
}

// Questao 11
// Verifica se árvore é estritamente binária
// se os nós possuem 0 ou 2 filhos

int estbin(TNoA *a)
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

// Questao 12
// Testa se duas árvores possuem os mesmos nós
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

// ARVORE BINARIA DE BUSCA

typedef struct ab
{
    int info;
    struct ab *esq, *dir;
} TABB;

// Questão 01
// Encontra o maior elemento da árvore
TABB *maior(TABB *a)
{
    if (!a)
    {
        return NULL;
    }
    TABB *maior_no = a;
    while (maior_no->dir)
    {
        maior_no = maior_no->dir;
    }
    return maior_no;
}

// Questão 02
// Encontra o menor elemento da árvore
TABB *menor(TABB *a)
{
    if (!a)
    {
        return NULL;
    }
    TABB *menor_no = a;
    while (menor_no->esq)
    {
        menor_no = menor_no->esq;
    }
    return menor_no;
}

// Questão 03
// Retira todos os elementos ímpares

TABB *retira_impares(TABB *a)
{
    if (!a)
    {
        return NULL;
    }

    a->esq = retira_impares(a->esq);
    a->dir = retira_impares(a->dir);

    // Caso NO FOLHA
    if (!a->esq && !a->dir && a->info % 2 != 0)
    {
        free(a);
        return NULL;
    }
    // CASO NO COM UM FILHO
    if (a->esq || a->dir && a->info % 2 != 0)
    {
        if (!a->esq)
        {
            TNoA *dir = a->dir;
            free(a);
            return dir;
        }
        if (!a->dir)
        {
            TNoA *esq = a->esq;
            free(a);
            return esq;
        }
    }
    // CASO NO COM DOIS FILHOS
    else
    {
        TNoA *atual = a->esq;
        TNoA *anterior = a;
        while (atual->dir)
        {
            anterior = atual;
            atual = atual->dir;
        }
        a->info = atual->info;
        free(atual);
        anterior->dir = NULL;

        return a;
    };
}

// Questão 4
// Retorna todos os valores menores que N
int qtd_menores(TABB *a, int N)
{
    if (!a)
    {
        return 0;
    }

    int contador = 0;
    if (a->info < N)
    {
        contador += 1;
    }

    contador += qtd_menores(a->esq, N);
    contador += qtd_menores(a->dir, N);

    return contador;
}

void grava_vetor(TABB *a, int N, int *vetor, int *contador)
{
    if (!a)
    {
        return;
    }

    if (a->info < N)
    {
        vetor[*contador] = a->info;
        *contador += 1;
    }

    grava_vetor(a->esq, N, vetor, contador);
    grava_vetor(a->dir, N, vetor, contador);
}

int *mN(TABB *a, int N)
{
    if (!a)
    {
        return NULL;
    }

    int n = qtd_menores(a, N);
    int *vetor = (int *)malloc(n * sizeof(int));
    int contador = 0;

    grava_vetor(a, N, vetor, &contador);

    return vetor;
}

// GRAFOS

// Questão 01
// Descobre quantidade de arestas
int na(TGrafo *g)
{
    // contador começa a 0
    int contador_vizinhos = 0;

    // guardo o primeiro vizinho em uma variável
    TVizinho *proximo = g->primeiro_vizinho;
    // enquanto eu tiver um proximo
    // somo 1 no contador
    // e vou para o proximo
    while (proximo)
    {
        contador_vizinhos += 1;
        proximo = proximo->prox;
    }

    // se o grafo tiver o proximo
    if (g->prox)
    {
        return contador_vizinhos + na(g->prox);
    }

    return contador_vizinhos;
}

// Questão 02
// Descobre a quantidade de vértices
int nv(TGrafo *g)
{
    int contador = 1;
    while (g)
    {
        g = g->prox;
        contador += 1;
    }
    return contador - 1;
}

// Questao 03
// Testar se dois grafos são iguais
int iguais(TGrafo *g1, TGrafo *g2)
{
    // Checo se ambos sao vazios: sao iguais
    if (!g1 && !g2)
    {
        return 1;
    }
    // se um dos dois é vazio: são diferentes
    if (!g1 || !g2)
    {
        return 0;
    }

    TVizinho *v1 = g1->primeiro_vizinho;
    TVizinho *v2 = g2->primeiro_vizinho;

    // se o g1 for igual ao g2
    // enqto existir um vizinho
    // se v1 for igual a v2 vai pro proximo e vai comparando
    // se nao, retorna 0 pq é diferente
    if (g1->id == g2->id)
    {
        while (v1 && v2)
        {
            if (v1->id_vizinho == v2->id_vizinho)
            {
                v1 = v1->prox;
                v2 = v2->prox;
            }
            else
            {
                return 0;
            }
        }
        // faz o mesmo para cada vertice
        return sao_iguais(g1->prox, g2->prox);
    }
}

// Questao 05
// Testa se nós vizinhos não possuem a mesma cor
// retorna 1 se cores diferentes e 0 se cores iguais

int nao_tem_mesma_cor(TGrafo *g)
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

int main(void)
{
    TNoA *raiz;
    TNoA *maior_no;
    TNoA *menor_no;
    raiz = criaNo('A');
    raiz->esq = criaNo('B');
    raiz->dir = criaNo('C');
    raiz->dir->esq = criaNo('D');
    raiz->dir->dir = criaNo('E');
    printf("arvore original: \n");
    imprime(raiz, 0);
    printf("\n");

    raiz = copia(raiz);
    printf("arvore copiada: \n");
    imprime(raiz, 0);
    printf("\n");

    raiz = espelho(raiz);
    printf("A arvore espelho é: \n");
    imprime(raiz, 0);
    printf("\n");

    printf("maior nó é: \n");
    maior_no = maior(raiz);
    imprime(maior_no, 0);

    printf("menor nó é: \n");
    menor_no = menor(raiz);
    imprime(menor_no, 0);

    printf("A quantidade de nós internos é: \n");
    int qtd_nos = ni(raiz);
    printf("%d", qtd_nos);
}