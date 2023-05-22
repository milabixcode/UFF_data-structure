
//implemente a função void altera(TLista* li, int vantigo, int vnovo) que altera o valor do campo INFO de uma lista encadeada li, 
//substituindo o valor vantigo pelo valor vnovo (ambos passados como parâmetro). Usar o arquivo lista-encadeada.c em anexo, que já 
//possui essa função declarada e algumas funções de apoio. Caso vantigo não exista na lista, ela deve permanecer inalterada.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct lista {
    int info;
    struct lista* prox;
} TLista;

// Alteração na lista:

// Parâmetros: lista, valor antigo, valor novo

// Implementação:

// Para cada nó da lista:
//     Se esse nó possuir informação igual ao antigo:
//         Atribuo o valor novo no info desse nó
//         Paro de procurar.


void altera(TLista* li, int vantigo, int vnovo) {
    //ponteiro para percorrer a lista
    TLista* p = li;

    //quando acho o valor antigo, substituo pelo novo
    while(p != NULL && p->info != vantigo){
        p = p->prox;
    }

    // oq é verdade?

    // R: !(p não é nulo e p->info é diferente de vantigo)

    // R: p é nulo ou p->info é igual vantigo

    if(p != NULL){
        p->info = vnovo;
    }
}

void imprime_lista(TLista *li) {
    TLista* p;
    for (p = li; p != NULL; p = p->prox)
        printf("%d ", p->info);
}

TLista* insere_fim (TLista* li, int i) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = NULL;
    TLista* p = li;
    TLista* q = li;
    while (p != NULL) {
        /* encontra o ultimo elemento */
        q = p;
        p = p->prox;
    }
    if (q != NULL) /* se a lista original não estiver vazia */
        q->prox = novo;
    else
        li = novo;
    return li;
}

int main (void) {
    /* A função main lê os dados de entrada, cria a lista e chama a função altera
     * depois imprime a lista resultante
     * Ela NÃO DEVE SER MODIFICADA
     * */
    TLista* lista = NULL;
    char l[100];
    char delimitador[] = "-";
    char *ptr;
    int valor;
    int valor_antigo, valor_novo;


    /* lê valores para criar a lista
     * valores devem ser informados separados por traço
     * exemplo: 1-3-5-2-7-9-21-6 */
    scanf("%s", l);
    //quebra a string de entrada
    ptr = strtok(l, delimitador);
    while(ptr != NULL) {
        valor = atoi(ptr);
        lista = insere_fim(lista, valor);
        ptr = strtok(NULL, delimitador);
    }

    //Le dados da alteracao a ser realizada
    scanf("%d", &valor_antigo);
    scanf("%d", &valor_novo);
    altera(lista, valor_antigo, valor_novo);
    imprime_lista(lista);
}

