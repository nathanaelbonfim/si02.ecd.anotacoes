#include "ListaDinEncad.h"
#include <malloc.h>

struct elemento {
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

int main(void) {
    Lista *li; // Ponteiro para ponteiro

    li = cria_lista();
    libera_lista(li);
    int x = tamanho_lista(li);
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
