#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *vet = (int *)calloc(10, sizeof(int));
    if (vet == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    printf("Valores inicializados com calloc:");
    for (int i = 0; i < 10; i++) {
        printf(" %d", vet[i]);
    }
    printf("\n");

    free(vet);
    vet = NULL;
    return 0;
}
