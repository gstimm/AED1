#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[30];
  int idade;
  int altura;
} Pessoa;

int main() {
  int choice, counter = 0;
  Pessoa *buffer = NULL;

  do {
    printf("Deseja incluir uma pessoa?\n");
    printf("1- Sim\n2- Não\n");
    scanf("%d", &choice);

    while (choice < 1 || choice > 2) {
      printf("Digite um valor valido.\n");
      printf("Deseja incluir uma pessoa?\n");
      printf("1- Sim\n2- Não\n");
      scanf("%d", &choice);
    }

    if (choice == 2) {
      if (counter == 0) {
        printf("Não há usuários cadastrados.\n");
        exit(1);
      }

      printf("Lista de Pessoas Cadastradas.\n");
      for (int i = 0; i < counter; i++) {
        printf("\tPessoa #%d\n", i + 1);
        printf("Nome: %s\n", buffer[i].nome);
        printf("Idade: %d anos\n", buffer[i].idade);
        printf("Altura: %d cm\n", buffer[i].altura);
      }

      free(buffer);
      exit(1);
    }

    if (counter == 0) {
      buffer = (Pessoa *)malloc(sizeof(Pessoa));
    } else {
      buffer = (Pessoa *)realloc(buffer, (counter + 1) * sizeof(Pessoa));
    }

    if (buffer == NULL) {
      printf("Falha na alocação de memória.\n");
      exit(1);
    }

    printf("Digite o nome da pessoa: ");
    scanf("%s", buffer[counter].nome);
    printf("Digite a idade da pessoa: ");
    scanf("%d", &buffer[counter].idade);
    printf("Digite a altura da pessoa: ");
    scanf("%d", &buffer[counter].altura);

    counter++;

  } while (1);
}