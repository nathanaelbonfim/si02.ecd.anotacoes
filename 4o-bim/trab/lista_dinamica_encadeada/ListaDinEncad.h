struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct elemento* Lista;

// Funções
Lista* cria_lista();
void libera_lista(Lista* li);
