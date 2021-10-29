#include <stdio.h>
#include <stdlib.h>
#define QUANTIDADE_POSICOES 5

int main() {
    int v[QUANTIDADE_POSICOES], n = QUANTIDADE_POSICOES, aux, i, c, teste = 1;
    int passos = 0;

    for (int i = 0; i < QUANTIDADE_POSICOES; i++) {
        printf("Digite um valor para a posição %d: ", i);
        scanf("%d", &v[i]);
    }


    for (i = 0; (i < n - 1) && (teste == 1); i++) {
        teste = 0;

        for (c = 0; c < n - i - 1; c++) {
            passos++;
            if (v[c] > v[c + 1]) {
                teste = 1;
                aux = v[c];
                v[c] = v[c + 1];
                v[c + 1] = aux;
            }
        }
    }

    printf("--------------\n");
    for (int i = 0; i < QUANTIDADE_POSICOES; i++) {
        printf("Posição %d: %d\n", i, v[i]);
    }
    printf("--------------\n");
    printf("Quantidade de passos necessários: %d\n", passos);
}
