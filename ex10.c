#include <stdio.h>

void imprimir_vetor(const int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf(" %d", vetor[i]);
    }
    printf("\n");
}

void bubble_sort(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int trocou = 0;
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                trocou = 1;
            }
        }
        if (!trocou) {
            break;
        }
    }
}

int main(void) {
    int vetor[8] = {64, 34, 25, 12, 22, 11, 90, 5};
    int tamanho = 8;

    printf("Vetor antes da ordenacao:");
    imprimir_vetor(vetor, tamanho);

    bubble_sort(vetor, tamanho);

    printf("Vetor depois da ordenacao:");
    imprimir_vetor(vetor, tamanho);

    return 0;
}
