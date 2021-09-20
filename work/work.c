#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(int *pBuffer);
void PUSH(void *pBuffer);
void POP(void *pBuffer);
void FIND(void *pBuffer);
void LIST(void *pBuffer);
void PRINT(void *person);
void SORT(void *pBuffer, void *person);
void CLEAR(void *pBuffer);

#define PREVIOUS 0
#define NAME (sizeof(void *))
#define AGE (sizeof(void *) + sizeof(char) * 10)
#define PHONE (sizeof(void *) + sizeof(char) * 10 + sizeof(int))
#define NEXT (sizeof(void *) + sizeof(char) * 10 + sizeof(int) * 2)

#define CHOICE 0
#define pFirst (sizeof(int))
#define pLast (sizeof(int) + sizeof(void *))
#define FIND_NAME (sizeof(int) + sizeof(void *) * 2)

int main() {
  void *pBuffer =
      (void *)malloc(sizeof(int) + sizeof(void *) * 2 + sizeof(char) * 10);

  if (pBuffer == NULL) {
    printf("Falha na alocação de memória.\n");
    exit(1);
  }

  int *choice = &*(int *)(pBuffer + CHOICE);

  *(void **)(pBuffer + pFirst) = NULL;
  *(void **)(pBuffer + pLast) = NULL;

  while (1) {
    menu(choice);
    switch (*choice) {
    case 1:
      PUSH(pBuffer);
      break;
    case 2:
      POP(pBuffer);
      break;
    case 3:
      FIND(pBuffer);
      break;
    case 4:
      LIST(pBuffer);
      break;
    case 5:
      CLEAR(pBuffer);
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

void PUSH(void *pBuffer) {
  void *person =
      (void *)malloc(sizeof(void *) * 2 + sizeof(char) * 10 + sizeof(int) * 2);

  if (person == NULL) {
    printf("Falha na alocação de memória.\n");
    exit(1);
  }

  do {
    printf("Digite um Nome de até 10 caracteres: ");
    scanf("%s", (char *)(person + NAME));
  } while (strlen((char *)(person + NAME)) > 10);

  printf("Digite a idade: ");
  scanf("%d", (int *)(person + AGE));

  printf("Digite o telefone: ");
  scanf("%d", (int *)(person + PHONE));

  SORT(pBuffer, person);
}

void SORT(void *pBuffer, void *person) {
  *(void **)(person + PREVIOUS) = NULL;
  *(void **)(person + NEXT) = NULL;

  void *auxPerson = *(void **)(pBuffer + pLast);

  if (auxPerson == NULL) {
    *(void **)(pBuffer + pFirst) = person;
    *(void **)(pBuffer + pLast) = person;
    return;
  }

  while (auxPerson != NULL) {
    if (strcmp((char *)(person + NAME), (char *)(auxPerson + NAME)) >= 0) {
      if (*(void **)(auxPerson + NEXT) == NULL) {
        *(void **)(person + PREVIOUS) = auxPerson;
        void *tempPerson = *(void **)(pBuffer + pLast);
        *(void **)(pBuffer + pLast) = person;
        *(void **)(tempPerson + NEXT) = person;

        return;
      } else {
        *(void **)(person + PREVIOUS) = auxPerson;
        *(void **)(person + NEXT) = *(void **)(auxPerson + NEXT);
        void *tempPerson = *(void **)(auxPerson + NEXT);
        *(void **)(tempPerson + PREVIOUS) = person;
        *(void **)(auxPerson + NEXT) = person;

        return;
      }
    }

    auxPerson = *(void **)(auxPerson + PREVIOUS);
  }

  *(void **)(person + NEXT) = *(void **)(pBuffer + pFirst);
  *(void **)(pBuffer + pFirst) = person;

  return;
}

void LIST(void *pBuffer) {
  void *person = *(void **)(pBuffer + pFirst);

  if (person == NULL) {
    printf("Lista vazia.\n");
    return;
  }

  do {
    PRINT(person);
    person = *(void **)(person + NEXT);
  } while (person != NULL);
}

void PRINT(void *person) {
  printf("Nome:     %s\n", (char *)(person + NAME));
  printf("Idade:    %d\n", *(int *)(person + AGE));
  printf("Telefone: %d\n", *(int *)(person + PHONE));
}

void FIND(void *pBuffer) {
  char *name = &*(char *)(pBuffer + FIND_NAME);
  void *person = *(void **)(pBuffer + pFirst);

  if (person == NULL) {
    printf("Lista vazia.\n");
    return;
  }

  printf("Nome que deseja buscar: ");
  scanf("%s", name);

  do {
    if (strcmp(name, (char *)(person + NAME)) == 0) {
      PRINT(person);
      return;
    }
    person = *(void **)(person + NEXT);
  } while (person != NULL);

  printf("Nome não encontrado.\n");
  return;
}

void POP(void *pBuffer) {
  void *person = *(void **)(pBuffer + pFirst);

  if (person == NULL) {
    printf("Lista vazia.\n");
    return;
  }

  if (*(void **)(person + NEXT) == NULL) {
    *(void **)(pBuffer + pFirst) = NULL;
    *(void **)(pBuffer + pLast) = NULL;
  } else {
    *(void **)(pBuffer + pFirst) = *(void **)(person + NEXT);
    void *auxPerson = *(void **)(pBuffer + pFirst);
    *(void **)(auxPerson + PREVIOUS) = NULL;
  }

  printf("Pessoa removida: %s\n", (char *)(person + NAME));
  free(person);
}

void CLEAR(void *pBuffer) {
  void *person = *(void **)(pBuffer + pFirst);
  void *auxPerson;

  while (person != NULL) {
    auxPerson = *(void **)(person + NEXT);
    free(person);
    person = auxPerson;
  }

  free(pBuffer);
}
