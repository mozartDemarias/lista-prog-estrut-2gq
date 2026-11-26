#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    *ptr = 42;
    printf("Valor armazenado antes do free: %d\n", *ptr);

    free(ptr);
    ptr = NULL;
    printf("Memoria liberada e ponteiro atribuido para NULL.\n");

    if (ptr != NULL) {
        printf("Leitura segura do ponteiro: %d\n", *ptr);
    } else {
        printf("Leitura evitada com seguranca: o ponteiro esta NULL.\n");
    }

    if (ptr != NULL) {
        *ptr = 99;
        printf("Escrita realizada: %d\n", *ptr);
    } else {
        printf("Escrita evitada com seguranca: nao ha dangling pointer.\n");
    }

    return 0;
}
