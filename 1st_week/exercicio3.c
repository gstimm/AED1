#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct user {
  char name[10];
  int age;
  long int phone;
} User;

int menu(void);
void *insertUser(void *pBuffer);
void *removeUser(void *pBuffer);
int findByName(void *pBuffer);
void listAll(void *pBuffer);

int main() {
  int choice, busca;
  void *pBuffer;

  pBuffer = malloc(sizeof(int));

  if (pBuffer == NULL) {
    printf("Falha na alocação de memória.\n");
    exit(1);
  }

  *(int *)pBuffer = 0;

  while (1) {
    choice = menu();
    switch (choice) {
    case 1:
      pBuffer = insertUser(pBuffer);
      break;
    case 2:
      pBuffer = removeUser(pBuffer);
      break;
    case 3:
      busca = findByName(pBuffer);
      break;
    case 4:
      listAll(pBuffer);
      break;
    case 5:
      free(pBuffer);
      exit(0);
      break;
    }
  }
}

int menu(void) {
  int choice = 0;
  do {
    printf("MENU:\n");
    printf("- 1. Inserir um usuário\n");
    printf("- 2. Excluir um usuário\n");
    printf("- 3. Buscar por nome\n");
    printf("- 4. Listar os usuários\n");
    printf("- 5. Sair\n");
    printf("Digite sua escolha: ");
    scanf("%d", &choice);
  } while (choice < 1 || choice > 5);
  getchar();
  return choice;
}

void *insertUser(void *pBuffer) {
  User newUser;
  printf("Digite o nome: ");
  scanf("%s[^\n]", newUser.name);
  printf("Digite a idade: ");
  scanf("%d", &newUser.age);
  printf("Digite o telefone: ");
  scanf("%ld", &newUser.phone);

  int size = *(int *)pBuffer;
  size++;
  pBuffer = realloc(pBuffer, sizeof(int) + (sizeof(User) * size));
  if (pBuffer == NULL) {
    printf("Falha na alocação de memória.\n");
    exit(1);
  }

  if (size == 1) {
    *(User *)(pBuffer + sizeof(int)) = newUser;
  } else {
    *(User *)(pBuffer + sizeof(int) + (size - 1) * sizeof(User)) = newUser;
  }

  *(int *)pBuffer = size;
  printf("Usuário adicionado com sucesso.\n");

  return pBuffer;
}

void *removeUser(void *pBuffer) {
  int size = *(int *)pBuffer;

  int userId = findByName(pBuffer);
  if (userId == -1) {
    return pBuffer;
  }

  User user = *(User *)(pBuffer + sizeof(int) + sizeof(User) * userId);
  if (userId + 1 < size) {
    User nextUser;
    for (int i = userId; i < size - 1; i++) {
      nextUser = *(User *)(pBuffer + sizeof(int) + sizeof(User) * (i + 1)); //recebe o prox
      *(User *)(pBuffer + sizeof(int) + sizeof(User) * i) = nextUser;       //sobrepoem o anterior
    }
  }

  size--;
  *(int *)pBuffer = size;

  pBuffer = realloc(pBuffer, sizeof(int) + sizeof(User) * size);
  if (pBuffer == NULL) {
    printf("Falha na alocação de memória.\n");
    exit(1);
  }

  printf("Usuário removido com sucesso!\n");

  return pBuffer;
}

int findByName(void *pBuffer) {
  int totalUsers = *(int *)pBuffer;

  if (totalUsers == 0) {
    printf("Não há usuários cadastrados.\n");
    return -1;
  }

  char name[10];
  printf("Digite o nome que deseja buscar: ");
  scanf("%s[^\n]", name);

  User user;

  for (int i = 0; i < totalUsers; i++) {
    user = *(User *)(pBuffer + sizeof(int) + i * sizeof(User));
    if (strcmp(user.name, name) == 0) {
      User user = *(User *)(pBuffer + sizeof(int) + sizeof(User) * i);
      printf("\n\tCONTATO #%d\n", i + 1);
      printf("Nome: %s\n", user.name);
      printf("Idade: %d\n", user.age);
      printf("Telefone: %ld\n", user.phone);
      return i;
    }
  }

  printf("Usuário não encontrado.\n");
  return -1;
}

void listAll(void *pBuffer) {
  int totalUsers = *(int *)pBuffer;
  if (totalUsers == 0) {
    printf("Nenhum Usuário para listar.\n");
    return;
  }

  User user;
  for (int i = 0; i < totalUsers; i++) {
    user = *(User *)(pBuffer + sizeof(int) + (sizeof(User) * i));
    printf("\n\tCONTATO #%d\n", i + 1);
    printf("Nome: %s\n", user.name);
    printf("Idade: %d\n", user.age);
    printf("Telefone: %ld\n", user.phone);
  }
}
