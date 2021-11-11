#include <stdio.h>
#include "header.h"

//-------------------------------------
// Header
//-------------------------------------
// Auxiliares
int menuPrincipal();
void mostrarLista(int *lista) {
    printf("--------------\n");
    for (int i = 0; i < sizeof(lista); i++) {
        printf("Posição %d: %d\n", i, lista[i]);
    }
    printf("--------------\n");
};

// Algoritmos de classificação
void algBubbleSort(int *lista) {
    for (int i = 0; i < sizeof(lista) - 1; i++) {
        for (int c = 0; c < (sizeof(lista) - 1); c++) {
            if (valores[c] > valores[c + 1]) {
                aux = valores[c];
                valores[c] = valores[c + 1];
                valores[c + 1] = aux;
            }
        }
    }
};

void algInsertionSort(int *lista) {
    int i, j, tmp;
    for(i = 1; i < MAX; i++) {
        tmp = lista[i];
        for(j = i-1; j >= 0 && tmp < lista[j]; j--) {
            lista[j+1] = lista[j];
        }
        lista[j+1] = tmp;
    }
};

void algSelectionSort(int *lista) {
    int i, j, k, tmp, troca;

    for(i = 0; i < MAX -1; i++) {
        troca = 0;
        k = i;
        tmp = lista[i];
        for(j = i+1; j < MAX; j++) {
            if(lista[j] < tmp) {
                k = j;
                tmp = lista[j];
                troca = 1; }}
        if(troca) {
            lista[k] = lista[i];
            lista[i] = tmp;
        }
    }
}

void algQuickSort(int *lista, int esq, int dir) {
    int i, j, x, y;
    i = esq;
    j = dir;
    x = lista[(esq + dir) / 2];

    while(i <= j) {
        while(lista[i] < x && i < dir) { i++; }
        while(lista[j] > x && j > esq) { j--; }
        if(i <= j) {
            y = lista[i];
            lista[i] = lista[j];
            lista[j] = y;
            i++; j--;
        }
    }
    if(j > esq) { quick_sort (a, esq, j); }
    if(i < dir) { quick_sort (a, i, dir); }
};
void algShellSort(int *lista, int size) {
    int i , j , value;
    int gap = 1;
    do {
        gap = 3*gap+1;
    } while(gap < size);
    do {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = lista[i];
            j = i - gap;
            while (j >= 0 && value < lista[j]) {
                lista[j + gap] = lista[j];
                j -= gap;
            }
            lista[j + gap] = value;
        }
    } while(gap > 1);
}
};
void algHeapSort(int *lista, int n) {
    int i, aux;
    for (i = (n-1)/2; i >= 0; i--) {
        heap (lista, i, n);
    }
    for (i = n-1; i >= 1; i--) {
        aux = lista[0];
        lista[0] = lista[i];
        lista[i] = aux;
        heap ( lista, 0, i-1 );
    }
}

void heap(int *vet, int i, int f) {
    int aux = vet[i];
    int j = i * 2 + 1;
    while (j <= f) {
        if (j < f) {
            if (vet[j] < vet[j+1]) { j++; }
        }
        if (aux < vet[j]) {
            vet[i] = vet[j];
            i = j;
            j = 2*i +1;
        }
        else { j = f+1; }
    }
    vet[i] = aux;
}

void algMergeSort(int *lista, int i, int f) {
    int meio;
    if (i < f) {
        meio = floor ((i+f)/2);
        mergeSort(lista, i, meio);
        mergeSort(lista, meio+1, f);
        merge(lista, i, meio, f);
    }
};

void merge(int *V, int inicio, int meio, int fim) {
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2=0;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int *) malloc (tamanho * sizeof(int));
    if (temp != NULL) {
        for (i=0; i < tamanho; i++){
            if (!fim1 && !fim2){
                if (V[p1] < V[p2]){
                    temp[i]=V[p1++];
                }
                else{
                    temp[i]=V[p2++];
                }
                if (p1>meio) fim1=1;
                if (p2>fim) fim2=1; }
            else{
                if (!fim1)
                    temp[i]=V[p1++];
                else
                    temp[i]=V[p2++];
            }
        }
        for (j=0, k=inicio; j<tamanho; j++, k++){
            V[k]=temp[j];
        }
    }
    free(temp);
}

//-------------------------------------

int aux;
int MAX = 5;

int main() {
    int opcaoMenu;
    int lista[5];

    for (int i = 0; i < 5; i++) {
        printf("Digite um valor para a posição %d: ", i);
        scanf("%d", &lista[i]);
    }

    mostrarLista(lista);

    do {
        opcaoMenu = menuPrincipal();
        switch (opcaoMenu) {
            case 1:
                algBubbleSort(lista);
                break;
            case 2:
                algInsertionSort(lista);
                break;
            case 3:
                algSelectionSort(lista);
                break;
            case 4:
                algQuickSort(lista, 0, 4);
                break;
            case 5:
                algShellSort(lista, 5);
                break;
            case 6:
                algHeapSort(lista, 5);
                break;
            case 7:
                algMergeSort(lista, 0, 5);
                break;
        }
        mostrarLista(lista); 
    } while (opcaoMenu != 0);
}

int menuPrincipal() {
    int escolha;
    printf("===============================\n");
    printf("  ALGORITMOS DE CLASSIFICAÇÃO  \n");
    printf("===============================\n");
    printf(" 1. Bubble Sort \n");
    printf(" 2. Insertion Sort\n");
    printf(" 3. Selection Sort\n");
    printf(" 4. Quicksort\n");
    printf(" 5. Shellsort\n");
    printf(" 6. HeapSort\n");
    printf(" 7. Merge Sort\n");
    printf("-------------------------------\n");
    printf(" 0. SAIR\n");
    printf("===============================\n");
    printf("-> ");
    scanf("%d", &escolha);

    return escolha;
}

