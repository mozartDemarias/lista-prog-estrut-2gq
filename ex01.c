#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *vet = (int *)malloc(5 * sizeof(int));
    if (vet == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    printf("Digite 5 inteiros:\n");
    for (int i = 0; i < 5; i++) {
        printf("Valor %d: ", i + 1);
        if (scanf("%d", &vet[i]) != 1) {
            printf("Entrada invalida.\n");
            free(vet);
            vet = NULL;
            return 1;
        }
    }

    printf("Valores digitados:");
    for (int i = 0; i < 5; i++) {
        printf(" %d", vet[i]);
    }
    printf("\n");

    free(vet);
    vet = NULL;
    return 0;
}
