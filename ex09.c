#include <stdio.h>

int pesquisa_sequencial(const int *vetor, int tamanho, int alvo) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == alvo) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int vetor[8] = {15, 42, 7, 23, 89, 12, 56, 31};
    int tamanho = 8;

    printf("Vetor:");
    for (int i = 0; i < tamanho; i++) {
        printf(" %d", vetor[i]);
    }
    printf("\n");

    int alvo = 0;
    printf("Digite o numero que deseja buscar: ");
    if (scanf("%d", &alvo) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    int pos = pesquisa_sequencial(vetor, tamanho, alvo);
    if (pos != -1) {
        printf("Elemento %d encontrado na posicao %d.\n", alvo, pos);
    } else {
        printf("Elemento %d nao existe no vetor.\n", alvo);
    }

    return 0;
}
