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
