/*
 * Crie um ponteiro que faça a alocação dinâmica (utilizando o comando malloc)
 * de 3 posições do tipo inteiro. Após isso, imprima os valores da variável
 * alocada. Num segundo momento peça para o usuário inserir os valores dentro
 * da variável alocada e por fim, imprima novamente os valores da variável
 * alocada. Não esqueça de, antes de finalizar a execução do algoritmo, liberar a
 * área de memória alocada (free).
 */

#include <stdio.h>
#include <malloc.h>

#define QUANTIDADE_POSICOES 5

int main() {
    int *p = (int *)malloc(QUANTIDADE_POSICOES * sizeof(int));

    for (int i = 0; i < QUANTIDADE_POSICOES; i++) {
        scanf("%d", (int *)&p[i]);
        //p[i] = i;
    }

    p = &p[0];
    for (int i = 0; i < QUANTIDADE_POSICOES; i++) {
        printf("%d", p[i]);
    }
}
