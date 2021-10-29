#include <stdlib.h>
#include <stdio.h>
#define QUANTIDADE_POSICOES 5

int main(void) {
    int a[QUANTIDADE_POSICOES], n = QUANTIDADE_POSICOES, troca = 1, ut = 0, c, aux, m = n - 1;
    int passos = 0;

    for (int i = 0; i < QUANTIDADE_POSICOES; i++) {
        printf("Digite um valor para a posição %d: ", i);
        scanf("%d", &a[i]);
    }

    while (troca == 1) {
        troca = 0;

        for (c = 0; c < m; c++) {
            passos++;
            if (a[c] > a[c + 1]) {
                aux = a[c];
                a[c] = a[c + 1];
                a[c + 1] = aux;

                ut = c;
                troca = 1;
            }
        }
    m = ut;
    }

    printf("--------------\n");
    for (int i = 0; i < QUANTIDADE_POSICOES; i++) {
        printf("Posição %d: %d\n", i, a[i]);
    }
    printf("--------------\n");
    printf("Quantidade de passos necessários: %d\n", passos);
}
