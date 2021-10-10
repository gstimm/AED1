#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
  int value;
  struct Node *pLeft;
  struct Node *pRight;
} Node;

int insert(Node **ppRoot, int value);
int balance(Node **ppRoot);
int balanceFactor(Node *pRoot);
int height(Node *pRoot);
int isAvlTree(Node *pRoot);
int leftBalance(Node **ppRoot);
int rightBalance(Node **ppRoot);
void simpleLeftRotation(Node **ppRoot);
void simpleRightRotation(Node **ppRoot);
void clearTree(Node *ppRoot);
void secondScenario();
void firstCaseA();
void firstCaseB();
void secondCaseA();
void secondCaseB();
void thirdCaseA();
void thirdCaseB();

int main() {
  int i = 0, value, nodeNumber;
  Node *ppRoot = NULL;

  printf("Digite a quantidade de nós: ");
  scanf("%d", &nodeNumber);

  srand(time(0));

  while (i < nodeNumber) {
    value = rand() % 100;
    printf("Valor inserido: %d\n", value);
    insert(&ppRoot, value);
    i++;
  }

  if (isAvlTree(ppRoot)) {
    printf("\nÉ uma Árvore AVL.\n");
  } else {
    printf("\nNão é uma Árvore AVL.\n");
  }

  clearTree(ppRoot);

  secondScenario();

  return 0;
}

int insert(Node **ppRoot, int value) {
  if (*ppRoot == NULL) {
    *ppRoot = (Node *)malloc(sizeof(Node));
    (*ppRoot)->value = value;
    (*ppRoot)->pLeft = NULL;
    (*ppRoot)->pRight = NULL;
    return 1; // bem sucedido
  } else if ((*ppRoot)->value > value) {
    if (insert(&(*ppRoot)->pLeft, value)) {
      if (balance(ppRoot)) {
        return 0; // houve balance;
      } else {
        return 1; // bem sucedido sem balance;
      }
    }
  } else if ((*ppRoot)->value < value) {
    if (insert(&(*ppRoot)->pRight, value)) {
      if (balance(ppRoot)) {
        return 0; // houve balance;
      } else {
        return 1; // bem sucedido sem balance;
      }
    }
  } else {
    printf("Valor já consta na árvore.\n");
    return 0;
  }
}

int balance(Node **ppRoot) {
  int fb = balanceFactor(*ppRoot);

  if (fb > 1) {
    return leftBalance(ppRoot);
  } else if (fb < -1) {
    return rightBalance(ppRoot);
  } else {
    return 0;
  }
}

int balanceFactor(Node *pRoot) {
  if (pRoot == NULL) return 0; // se não tiver nenhum elemento, FB = 0

  return height(pRoot->pLeft) -
         height(pRoot->pRight); // retorna o resultado da subtração da height da
                                // esquerda com a da direita;
}

int height(Node *pRoot) {
  int left, right;

  if (pRoot == NULL) {
    return 0; // se não houver um nó, height 0
  }

  left = height(pRoot->pLeft);
  right = height(pRoot->pRight); // chama a próprioa função para calcular a
                                 // height do próprio nó

  if (left > right) {
    return left + 1;
  } else {
    return right + 1;
  }
}

void simpleLeftRotation(Node **ppRoot) {
  Node *pAux;

  pAux = (*ppRoot)->pRight;
  (*ppRoot)->pRight = pAux->pLeft;
  pAux->pLeft = (*ppRoot);
  (*ppRoot) = pAux;
}

void simpleRightRotation(Node **ppRoot) {
  Node *pAux;

  pAux = (*ppRoot)->pLeft;
  (*ppRoot)->pLeft = pAux->pRight;
  pAux->pRight = (*ppRoot);
  (*ppRoot) = pAux;
}

int leftBalance(Node **ppRoot) {
  int LBF = balanceFactor((*ppRoot)->pLeft);

  if (LBF >= 0) {
    simpleRightRotation(ppRoot);
    printf("Rotação Simples à Direita\n");
    return 1;
  } else if (LBF < 0) {
    simpleLeftRotation(&((*ppRoot)->pLeft));
    simpleRightRotation(ppRoot);
    printf("Rotação Dupla à Direita\n");
    return 1;
  }
  return 0;
}

int rightBalance(Node **ppRoot) {
  int RBF = balanceFactor((*ppRoot)->pRight);

  if (RBF <= 0) {
    simpleLeftRotation(ppRoot);
    printf("Rotação Simples à Esquerda\n");
    return 1;
  } else if (RBF > 0) {
    simpleRightRotation(&((*ppRoot)->pRight));
    simpleLeftRotation(ppRoot);
    printf("Rotação Dupla à Esquerda\n");
    return 1;
  }
  return 0;
}

void clearTree(Node *ppRoot) {
  if (ppRoot == NULL) return;

  clearTree(ppRoot->pLeft);
  clearTree(ppRoot->pRight);

  free(ppRoot);
}

int isAvlTree(Node *ppRoot) {
  int BF;
  BF = balanceFactor(ppRoot);

  if (ppRoot == NULL) return 1;

  if (!isAvlTree(ppRoot->pLeft)) return 0;

  if (!isAvlTree(ppRoot->pRight)) return 0;

  if ((BF > 1) || (BF < -1)) {
    return 0;
  } else {
    return 1;
  }
}

void printTree(Node *ppRoot) {
  if (ppRoot != NULL) {
    printf("%d(", ppRoot->value);
    printTree(ppRoot->pLeft);
    printTree(ppRoot->pRight);
    printf(")");
  }
}

void secondScenario() {
  printf("\n\t--CASO 1A--\n");
  firstCaseA();
  printf("\n\t--CASO 2A--\n");
  secondCaseA();
  printf("\n\t--CASO 3A--\n");
  thirdCaseA();
  printf("\n\t--CASO 1B--\n");
  firstCaseB();
  printf("\n\t--CASO 2B--\n");
  secondCaseB();
  printf("\n\t--CASO 3B--\n");
  thirdCaseB();
}

void firstCaseA() {
  Node *ppRoot = NULL;
  int value;
  value = 20;
  insert(&ppRoot, value);
  value = 4;
  insert(&ppRoot, value);
  printTree(ppRoot);
  if (isAvlTree(ppRoot)) {
    printf("\nÉ uma Árvore AVL.\n");
  } else {
    printf("\nNão é uma Árvore AVL.\n");
  }
  printf("\n\n");
  value = 15;
  insert(&ppRoot, value);
  printTree(ppRoot);
  if (isAvlTree(ppRoot)) {
    printf("\nÉ uma Árvore AVL.\n");
  } else {
    printf("\nNão é uma Árvore AVL.\n");
  }
  clearTree(ppRoot);
}

void secondCaseA() {
  Node *ppRoot = NULL;
  int value;
  value = 20;
  insert(&ppRoot, value);
  value = 4;
  insert(&ppRoot, value);
  value = 26;
  insert(&ppRoot, value);
  value = 3;
  insert(&ppRoot, value);
  value = 9;
  insert(&ppRoot, value);
  printTree(ppRoot);
  if (isAvlTree(ppRoot)) {
    printf("\nÉ uma Árvore AVL.\n");
  } else {
    printf("\nNão é uma Árvore AVL.\n");
  }
  printf("\n\n");
  value = 15;
  insert(&ppRoot, value);
  printTree(ppRoot);
  if (isAvlTree(ppRoot)) {
    printf("\nÉ uma Árvore AVL.\n");
  } else {
    printf("\nNão é uma Árvore AVL.\n");
  }

  clearTree(ppRoot);
}

void thirdCaseA() {
  Node *ppRoot = NULL;
  int value;
  value = 20;
  insert(&ppRoot, value);
  value = 4;
  insert(&ppRoot, value);
  value = 26;
  insert(&ppRoot, value);
  value = 3;
  insert(&ppRoot, value);
  value = 9;
  insert(&ppRoot, value);
  value = 2;
  insert(&ppRoot, value);
  value = 7;
  insert(&ppRoot, value);
  value = 11;
  insert(&ppRoot, value);
  value = 21;
  insert(&ppRoot, value);
  value = 30;
  insert(&ppRoot, value);
  printTree(ppRoot);
  if (isAvlTree(ppRoot)) {
    printf("\nÉ uma Árvore AVL.\n");
  } else {
    printf("\nNão é uma Árvore AVL.\n");
  }
  printf("\n\n");
  value = 15;
  insert(&ppRoot, value);
  printTree(ppRoot);
  if (isAvlTree(ppRoot)) {
    printf("\nÉ uma Árvore AVL.\n");
  } else {
    printf("\nNão é uma Árvore AVL.\n");
  }
  clearTree(ppRoot);
}

void firstCaseB() {
  Node *ppRoot = NULL;
  int value;
  value = 20;
  insert(&ppRoot, value);
  value = 4;
  insert(&ppRoot, value);
  printTree(ppRoot);
  if (isAvlTree(ppRoot)) {
    printf("\nÉ uma Árvore AVL.\n");
  } else {
    printf("\nNão é uma Árvore AVL.\n");
  }
  printf("\n\n");
  value = 8;
  insert(&ppRoot, value);
  printTree(ppRoot);
  if (isAvlTree(ppRoot)) {
    printf("\nÉ uma Árvore AVL.\n");
  } else {
    printf("\nNão é uma Árvore AVL.\n");
  }
  clearTree(ppRoot);
}

void secondCaseB() {
  Node *ppRoot = NULL;
  int value;
  value = 20;
  insert(&ppRoot, value);
  value = 4;
  insert(&ppRoot, value);
  value = 26;
  insert(&ppRoot, value);
  value = 3;
  insert(&ppRoot, value);
  value = 9;
  insert(&ppRoot, value);
  printTree(ppRoot);
  if (isAvlTree(ppRoot)) {
    printf("\nÉ uma Árvore AVL.\n");
  } else {
    printf("\nNão é uma Árvore AVL.\n");
  }
  printf("\n\n");
  value = 8;
  insert(&ppRoot, value);
  printTree(ppRoot);
  if (isAvlTree(ppRoot)) {
    printf("\nÉ uma Árvore AVL.\n");
  } else {
    printf("\nNão é uma Árvore AVL.\n");
  }

  clearTree(ppRoot);
}

void thirdCaseB() {
  Node *ppRoot = NULL;
  int value;
  value = 20;
  insert(&ppRoot, value);
  value = 4;
  insert(&ppRoot, value);
  value = 26;
  insert(&ppRoot, value);
  value = 3;
  insert(&ppRoot, value);
  value = 9;
  insert(&ppRoot, value);
  value = 2;
  insert(&ppRoot, value);
  value = 7;
  insert(&ppRoot, value);
  value = 11;
  insert(&ppRoot, value);
  value = 21;
  insert(&ppRoot, value);
  value = 30;
  insert(&ppRoot, value);
  printTree(ppRoot);
  if (isAvlTree(ppRoot)) {
    printf("\nÉ uma Árvore AVL.\n");
  } else {
    printf("\nNão é uma Árvore AVL.\n");
  }
  printf("\n\n");
  value = 8;
  insert(&ppRoot, value);
  printTree(ppRoot);
  if (isAvlTree(ppRoot)) {
    printf("\nÉ uma Árvore AVL.\n");
  } else {
    printf("\nNão é uma Árvore AVL.\n");
  }
  clearTree(ppRoot);
}