#include <stdio.h>

struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

int main(void) {
    struct Pessoa pessoa_escrita = {"Maria Oliveira", 25, 1.68f};

    FILE *arquivo = fopen("pessoa.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo binario para escrita.\n");
        return 1;
    }

    if (fwrite(&pessoa_escrita, sizeof(struct Pessoa), 1, arquivo) != 1) {
        printf("Erro ao gravar dados no arquivo binario.\n");
        fclose(arquivo);
        return 1;
    }

    if (fclose(arquivo) != 0) {
        printf("Erro ao fechar arquivo binario apos escrita.\n");
        return 1;
    }

    struct Pessoa pessoa_lida = {0};
    arquivo = fopen("pessoa.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo binario para leitura.\n");
        return 1;
    }

    if (fread(&pessoa_lida, sizeof(struct Pessoa), 1, arquivo) != 1) {
        printf("Erro ao ler dados do arquivo binario.\n");
        fclose(arquivo);
        return 1;
    }

    if (fclose(arquivo) != 0) {
        printf("Erro ao fechar arquivo binario apos leitura.\n");
        return 1;
    }

    printf("Dados lidos do arquivo binario:\n");
    printf("Nome: %s\n", pessoa_lida.nome);
    printf("Idade: %d\n", pessoa_lida.idade);
    printf("Altura: %.2f\n", pessoa_lida.altura);

    return 0;
}
