#include <stdio.h>
#include <stdlib.h>
#define LIMITE_DADOS 5

//================================
// Funções auxiliares
//================================

// Substitui o fflush(stdin) que não funciona no linux
void limparBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) { }
}

// Limpa a tela no Windows e Linux
void limpaTela() {
    #ifdef WINDOWS
        system("cls");
    #else
        system("clear");
    #endif
}

void pausa() {
    getchar();
}

int menu() {
    int escolha;
    printf("\n=============================\n");
    printf("=     TRABALHO DE ECD       =\n");
    printf("=============================\n");
    printf("= 1. Cadastrar dados\n");
    printf("= 2. Imprimir dados\n");
    printf("= 3. Busca sequencial\n");
    printf("= 4. Classificação (bubble sort)\n");
    printf("= 5. Busca binária\n");
    printf("= 6. SAIR\n");
    printf("=============================\n");
    scanf("%d", &escolha);

    return escolha;
}

void cadastrarDados(int lista[]) {
    printf("--------------\n");
    for (int i = 0; i < LIMITE_DADOS; i++) {
        printf("Posição %d: ", i);
        scanf("%d", &lista[i]);
    }
    printf("--------------\n");
}

int mostrarDados(int* lista) {
    limpaTela();
    printf("--------------\n");
    for (int i = 0; i < LIMITE_DADOS; i++) {
        printf("Posição %d: %d\n", i, lista[i]);
    }
    printf("--------------\n");
    pausa();
}

int buscaSequencial(int* lista) {
    int pesq, pont = -1, soma = 0;

    printf("\nEntre com o valor a ser pesquisado: ");
    scanf("%d", &pesq);

    for (int i = 0; i < LIMITE_DADOS; i++) {
        if (lista[i] == pesq) {
            pont = i;
            soma++;
        }
    }
    if (pont != -1) {
        printf("\nA quantidade de vezes que encontrou o valor %d foi %d", lista[pont], soma);
    } else {
        printf("\nValor não encontrado.");
    }
}

int classificacao(int *lista) {
    int aux;
    for (int i = 0; i < LIMITE_DADOS - 1; i++) {
        for (int c = 0; c < (LIMITE_DADOS - i - 1); c++) {
            if (lista[c] > lista[c + 1]) {
                aux = lista[c];
                lista[c] = lista[c + 1];
                lista[c + 1] = aux;
            }
        }
    }

}

int binaria(int *lista) {
    int pesq;
    int meio = sizeof(lista) / 2;
    int esq = 0, dir = sizeof(lista) - 1;
    printf("\nEntre com o valor a ser pesquisado: ");
    scanf("%d", &pesq);

    while (esq <= dir) {
        meio = (esq + dir) / 2;
        if (lista[meio] == pesq)
            return (meio);
        if (lista[meio] < pesq)
            esq = meio + 1;
        else
            dir = meio - 1;
    }
    return (-1);
}

int buscaBinaria(int *lista) {
    int pont = binaria(&lista);


    if (pont = -1) {
        printf("Valor encontrado!\n");
    } else {
        printf("Valor não encontrado.\n");
    }
    pausa();
}

int main() {
    int escolha;
    int dados[5];

    do {
        escolha = menu();

        switch (escolha) {
        case 1:
            cadastrarDados(&dados);
            break;
        case 2:
            mostrarDados(dados);
            break;
        case 3:
            buscaSequencial(dados);
            break;
        case 4:
            classificacao(dados);
            break;
        case 5:
            buscaBinaria(dados);
            break;
        
        default:
            break;
        }
    } while (escolha != 6);
}