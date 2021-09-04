#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(int *pBuffer);
void insertUser(void *pBuffer);
void removeUser(void *pBuffer);
void findByName(void *pBuffer);
void listAll(void *pBuffer);

#define OPTION 0
#define PEOPLE_COUNTER (sizeof(int))
#define COUNTER (sizeof(int) * 2)
#define NAME_POSITION (sizeof(int) * 3)
#define MAX_PEOPLE 10

typedef struct {
  char name[10];
  int age;
  long int phone;
} Pessoa;

Pessoa pessoas[10];

int main() {
  void *pBuffer = NULL;

  pBuffer = malloc(sizeof(int) * 3 + sizeof(char) * 11);

  if (pBuffer == NULL) {
    printf("Falha na alocação de memória.\n");
    exit(1);
  }

  int *choice = &*(int *)(pBuffer + OPTION);
  *(int *)(pBuffer + PEOPLE_COUNTER) = 0;

  while (1) {
    menu(choice);
    switch (*choice) {
    case 1:
      insertUser(pBuffer);
      break;
    case 2:
      removeUser(pBuffer);
      break;
    case 3:
      findByName(pBuffer);
      break;
    case 4:
      listAll(pBuffer);
      break;
    case 5:
      printf("SAINDO");
      free(pBuffer);
      exit(0);
      break;
    default:
      printf("Opção inválida.\n");
      break;
    }
  }
}

void menu(int *choice) {
  printf("MENU:\n");
  printf("- 1. Inserir um usuário\n");
  printf("- 2. Excluir um usuário\n");
  printf("- 3. Buscar por nome\n");
  printf("- 4. Listar os usuários\n");
  printf("- 5. Sair\n");
  printf("Digite sua escolha: ");
  scanf("%d", &*choice);
}

void insertUser(void *pBuffer) {
  int *peopleCounter = &*(int *)(pBuffer + PEOPLE_COUNTER);

  if (*peopleCounter >= MAX_PEOPLE) {
    printf("Não é possivel adicionar mais pessoas, pois a lista está cheia.\n");
    return;
  }

  printf("Digite o nome da pessoa: ");
  scanf("%s", pessoas[*peopleCounter].name);
  printf("Digite a idade da pessoa: ");
  scanf("%d", &pessoas[*peopleCounter].age);
  printf("Digite o telefone da pessoa: ");
  scanf("%lu", &pessoas[*peopleCounter].phone);

  *peopleCounter += 1;
}

void listAll(void *pBuffer) {
  int *peopleCounter = &*(int *)(pBuffer + PEOPLE_COUNTER);
  int *counter = &*(int *)(pBuffer + COUNTER);

  if (*peopleCounter == 0) {
    printf("Nenhuma pessoa para listar.\n");
    return;
  }

  for (*counter = 0; *counter < *peopleCounter; *counter += 1) {
    printf("\tPessoa #%d\n", *counter + 1);
    printf("Nome: %s\n", pessoas[*counter].name);
    printf("Idade: %d anos\n", pessoas[*counter].age);
    printf("Telefone: %lu\n", pessoas[*counter].phone);
  }
}

void findByName(void *pBuffer) {
  char *name = &*(char *)(pBuffer + NAME_POSITION);
  int *peopleCounter = &*(int *)(pBuffer + PEOPLE_COUNTER);
  int *counter = &*(int *)(pBuffer + COUNTER);

  if (*peopleCounter == 0) {
    printf("Não há pessoas para filtrar, pois a lista está vazia.\n");
    return;
  }

  printf("Digite o nome da pessoa que deseja filtrar: ");
  scanf("%s", name);

  for (*counter = 0; *counter < *peopleCounter; *counter += 1) {
    if (strcmp(name, pessoas[*counter].name) == 0) {
      printf("\tPessoa #%d\n", *counter + 1);
      printf("Nome: %s\n", pessoas[*counter].name);
      printf("Idade: %d anos\n", pessoas[*counter].age);
      printf("Telefone: %lu\n", pessoas[*counter].phone);
      return;
    }
  }

  printf("Pessoa não encontrada.\n");
  return;
}

void removeUser(void *pBuffer) {
  char *name = &*(char *)(pBuffer + NAME_POSITION);
  int *peopleCounter = &*(int *)(pBuffer + PEOPLE_COUNTER);
  int *counter = &*(int *)(pBuffer + COUNTER);

  if (*peopleCounter == 0) {
    printf("Não há pessoas para remover, pois a lista está vazia.\n");
    return;
  }

  printf("Digite o nome da pessoa que deseja remover: ");
  scanf("%s", name);

  for (*counter = 0; *counter < *peopleCounter; *counter += 1) {
    if (strcmp(name, pessoas[*counter].name) == 0) {
      break;
    }
  }
  if (*counter == *peopleCounter) {
    printf("Pessoa não encontrada.\n");
    return;
  }

  for (*counter; *counter < *peopleCounter; *counter += 1) {
    strcpy(pessoas[*counter].name, pessoas[*counter + 1].name);
    pessoas[*counter].age = pessoas[*counter + 1].age;
    pessoas[*counter].phone = pessoas[*counter + 1].phone;
  }

  *peopleCounter -= 1;

  return;
}