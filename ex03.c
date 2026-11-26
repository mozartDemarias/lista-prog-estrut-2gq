#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *vet = (int *)malloc(3 * sizeof(int));
    if (vet == NULL) {
        printf("Erro ao alocar memoria inicial.\n");
        return 1;
    }

    printf("Digite os 3 inteiros iniciais:\n");
    for (int i = 0; i < 3; i++) {
        printf("Posicao %d: ", i);
        if (scanf("%d", &vet[i]) != 1) {
            printf("Entrada invalida.\n");
            free(vet);
            vet = NULL;
            return 1;
        }
    }

    int *temp = (int *)realloc(vet, 6 * sizeof(int));
    if (temp == NULL) {
        printf("Erro ao realocar memoria.\n");
        free(vet);
        vet = NULL;
        return 1;
    }
    vet = temp;

    printf("Digite os 3 novos inteiros:\n");
    for (int i = 3; i < 6; i++) {
        printf("Posicao %d: ", i);
        if (scanf("%d", &vet[i]) != 1) {
            printf("Entrada invalida.\n");
            free(vet);
            vet = NULL;
            return 1;
        }
    }

    printf("Vetor completo:");
    for (int i = 0; i < 6; i++) {
        printf(" %d", vet[i]);
    }
    printf("\n");

    free(vet);
    vet = NULL;
    return 0;
}
