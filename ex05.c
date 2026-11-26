#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 0;
    printf("Digite o tamanho do vetor: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Tamanho invalido.\n");
        return 1;
    }

    int *vet = (int *)malloc((size_t)n * sizeof(int));
    if (vet == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    printf("Digite os %d elementos:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i);
        if (scanf("%d", &vet[i]) != 1) {
            printf("Entrada invalida.\n");
            free(vet);
            vet = NULL;
            return 1;
        }
    }

    printf("Elementos do vetor:");
    for (int i = 0; i < n; i++) {
        printf(" %d", vet[i]);
    }
    printf("\n");

    free(vet);
    vet = NULL;
    return 0;
}
