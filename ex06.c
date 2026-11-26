#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    char nome[100];
    int idade;
};

int main(void) {
    struct Aluno *aluno = (struct Aluno *)malloc(sizeof(struct Aluno));
    if (aluno == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    printf("Digite o nome do aluno: ");
    if (fgets(aluno->nome, sizeof(aluno->nome), stdin) == NULL) {
        printf("Erro ao ler nome.\n");
        free(aluno);
        aluno = NULL;
        return 1;
    }
    aluno->nome[strcspn(aluno->nome, "\r\n")] = '\0';

    printf("Digite a idade do aluno: ");
    if (scanf("%d", &aluno->idade) != 1) {
        printf("Idade invalida.\n");
        free(aluno);
        aluno = NULL;
        return 1;
    }

    printf("Dados do aluno:\n");
    printf("Nome: %s\n", aluno->nome);
    printf("Idade: %d\n", aluno->idade);

    free(aluno);
    aluno = NULL;
    return 0;
}
