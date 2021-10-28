#include <stdlib.h>
#include <stdio.h>
#define QUANTIDADE_POSICOES 5

int main(void) {
    int valores[QUANTIDADE_POSICOES];
    int passos = 0;
    int ordenado = 1;

    for (int i = 0; i < QUANTIDADE_POSICOES; i++) {
        printf("Digite um valor para a posição %d: ", i);
        scanf("%d", &valores[i]);
    }


    int aux;
    ordenado = 1;

    for (int i = 0; i < QUANTIDADE_POSICOES - 1; i++) {
        for (int c = 0; (c < (QUANTIDADE_POSICOES - i - 1) && ordenado == 1); c++) {
            if (valores[c] > valores[c + 1]) {
                ordenado = 1;
                aux = valores[c];
                valores[c] = valores[c + 1];
                valores[c + 1] = aux;
            }
            passos++;
        }
    }


    printf("--------------\n");
    for (int i = 0; i < QUANTIDADE_POSICOES; i++) {
        printf("Posição %d: %d\n", i, valores[i]);
    }
    printf("--------------\n");
    printf("Quantidade de passos necessários: %d\n", passos);
}
