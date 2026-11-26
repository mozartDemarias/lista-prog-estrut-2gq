#include <stdio.h>

int main(void) {
    const char *nomes[5] = {
        "Ana Silva",
        "Bruno Costa",
        "Carlos Souza",
        "Daniela Lima",
        "Eduardo Alves"
    };

    FILE *arquivo = fopen("nomes.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para escrita.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        if (fprintf(arquivo, "%s\n", nomes[i]) < 0) {
            printf("Erro ao escrever no arquivo.\n");
            fclose(arquivo);
            return 1;
        }
    }

    if (fclose(arquivo) != 0) {
        printf("Erro ao fechar arquivo apos escrita.\n");
        return 1;
    }

    arquivo = fopen("nomes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para leitura.\n");
        return 1;
    }

    char linha[100];
    printf("Nomes lidos do arquivo:\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    if (fclose(arquivo) != 0) {
        printf("Erro ao fechar arquivo apos leitura.\n");
        return 1;
    }

    return 0;
}
