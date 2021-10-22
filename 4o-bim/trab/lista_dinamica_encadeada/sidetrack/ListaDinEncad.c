#include "ListaDinEncad.h"
#include <malloc.h>

struct elemento {
    struct pagina dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

int main(void) {
    Lista *li; // Ponteiro para ponteiro

    li = cria_lista();
    libera_lista(li);

    struct pagina dados_pagina;

    int x = insere_lista_inicio(li, dados_pagina);
}

Lista* cria_lista() {
    Lista* li = (Lista*)malloc(sizeof(Lista));

    // Caso seja nulo, não foi possível criar a lista
    if (li == NULL) *li = NULL;

    return li;
}

void libera_lista(Lista* li) {
    if (li != NULL) {
        Elem* no;

        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista* li) {
    if (li == NULL) { return 0; }
    int cont = 0;
    Elem* no = *li;

    while (no != NULL) {
        cont++;
        no = no->prox;
    }

    return cont;
}

int lista_cheia(Lista* li) {
    return 0;
}

int lista_vazia(Lista* li) {
    if (li == NULL) return 1;  // Lista inexistente
    if (*li == NULL) return 1; // Conteúdo vazio

    return 0;
}

int insere_lista_inicio(Lista* li, struct pagina al) {
    if (li = NULL) return 0; // Lista inexistente
    Elem* no = (Elem*)malloc(sizeof(Elem));

    if (no == NULL) return 0; 

    no->dados = al;
    no->prox = (*li);
    *li = no;

    return 1;
}

int insere_lista_final(Lista* li, struct pagina al) {
    if (li == NULL) return 0;

    Elem* no = (Elem*)malloc(sizeof(Elem));
    if (no == NULL) return 0;
    no->dados = al;
    no->prox = NULL;

    if ((*li) == NULL) {
        Elem *aux = *li;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
    }

    return 1;
}

