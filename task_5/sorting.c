#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void PrintVector(int dataVector[], int totalElements);
void CheckOrder(int dataVector[], int totalElements);
void ChooseAlgorithm(int choice, int dataVector[], int totalElements);
void FillVector(int dataVector[], int totalElements);
void InsertionSort(int dataVector[], int totalElements);
void SelectionSort(int dataVector[], int totalElements);
void QuickSort(int dataVector[], int startIndex, int endIndex);
void MergeSort(int dataVector[], int length, int left, int right);
void Merge(int dataVector[], int length, int left, int middle, int right);

int main() {
  int totalElements, choice;
  srand(time(NULL));

  printf("Informe a quantidade de elementos do vetor: ");
  scanf("%d", &totalElements);

  int dataVector[totalElements];

  FillVector(dataVector, totalElements);

  PrintVector(dataVector, totalElements);

  printf("Qual algoritmo deseja usar? \n");
  printf("\t1. Insertion\n\t2. Selection\n\t3. Quick\n\t4. Merge\n");
  scanf("%d", &choice);

  ChooseAlgorithm(choice, dataVector, totalElements);

  CheckOrder(dataVector, totalElements);
  PrintVector(dataVector, totalElements);
  return 0;
}

void ChooseAlgorithm(int choice, int dataVector[], int totalElements) {
  struct timeval begin, end;
  long seconds;
  long microseconds;
  double elapsed;
  switch (choice) {
  case 1:
    printf("\tInsertion Sort\n");
    gettimeofday(&begin, 0);
    InsertionSort(dataVector, totalElements);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds * 1e-6;
    printf("Time measured: %.9f seconds.\n", elapsed);
    break;
  case 2:
    printf("\tSelection Sort\n");
    gettimeofday(&begin, 0);
    SelectionSort(dataVector, totalElements);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds * 1e-6;
    printf("Time measured: %.9f seconds.\n", elapsed);
    break;
  case 3:
    printf("\tQuick Sort\n");
    gettimeofday(&begin, 0);
    QuickSort(dataVector, 0, totalElements - 1);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds * 1e-6;
    printf("Time measured: %.9f seconds.\n", elapsed);
    break;
  case 4:
    printf("\tMerge Sort\n");
    gettimeofday(&begin, 0);
    MergeSort(dataVector, totalElements, 0, totalElements - 1);
    gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds * 1e-6;
    printf("Time measured: %.9f seconds.\n", elapsed);
    break;
  default:
    printf("Opção inválida.\n");
    break;
  }
}

void InsertionSort(int dataVector[], int totalElements) {
  int indexAux, key;
  for (int i = 1; i < totalElements; i++) {
    key = dataVector[i];
    indexAux = i - 1;
    while (indexAux >= 0 && dataVector[indexAux] > key) {
      dataVector[indexAux + 1] = dataVector[indexAux];
      indexAux--;
    }
    dataVector[indexAux + 1] = key;
  }
}

void SelectionSort(int dataVector[], int totalElements) {
  int smallValue, key, smallValueIndex;

  for (int i = 0; i <= totalElements; i++) {
    smallValueIndex = i;
    smallValue = dataVector[i];

    for (int j = i + 1; j < totalElements; j++) {
      if (dataVector[j] < smallValue) {
        smallValue = dataVector[j];
        smallValueIndex = j;
      }
    }

    key = dataVector[i];
    dataVector[i] = dataVector[smallValueIndex];
    dataVector[smallValueIndex] = key;
  }
}

void QuickSort(int dataVector[], int startIndex, int endIndex) {
  int pivot, key;
  int i = startIndex, j = endIndex;
  pivot = dataVector[(startIndex + endIndex) / 2];

  do {
    while (dataVector[i] < pivot) { // Busca o maior valor
      i++;
    }
    while (dataVector[j] > pivot) { // Busca o menor valor
      j--;
    }
    if (i <= j) {
      key = dataVector[i];
      dataVector[i] = dataVector[j];
      dataVector[j] = key;
      i++;
      j--;
    }
  } while (i <= j);
  if (startIndex < j) {
    QuickSort(dataVector, startIndex, j);
  }
  if (endIndex > j) {
    QuickSort(dataVector, i, endIndex);
  }
}

void MergeSort(int dataVector[], int length, int left, int right) {
  if (left >= right) {
    return;
  }

  int middle = (left + right) / 2;

  // Chamadas recursivas para dividir o vetor
  MergeSort(dataVector, length, left, middle);
  MergeSort(dataVector, length, middle + 1, right);

  if (dataVector[middle] <= dataVector[middle + 1]) { // se já estiver ordenado
    return;
  }
  Merge(dataVector, length, left, middle, right); // merge de todas as partes
}

void Merge(int dataVector[], int length, int left, int middle, int right) {
  int indexAux = left, dataVectorIndex = left, nextIndex = middle + 1;
  int auxVector[length];

  // Copia o vetor para um auxiliar
  for (int i = left; i <= right; i++) {
    auxVector[i] = dataVector[i];
  }

  while (dataVectorIndex <= middle && nextIndex <= right) {
    if (auxVector[dataVectorIndex] <= auxVector[nextIndex]) {
      dataVector[indexAux] = auxVector[dataVectorIndex];
      dataVectorIndex++;
    } else {
      dataVector[indexAux] = auxVector[nextIndex];
      nextIndex++;
    }
    indexAux++;
  }

  while (dataVectorIndex <= middle) {
    dataVector[indexAux] = auxVector[dataVectorIndex];
    indexAux++;
    dataVectorIndex++;
  }

  while (nextIndex <= right) {
    dataVector[indexAux] = auxVector[nextIndex];
    indexAux++;
    nextIndex++;
  }
}

void FillVector(int dataVector[], int totalElements) {
  int i = 0;
  while (i < totalElements) {
    dataVector[i] = rand() % totalElements;
    i++;
  }
}

void PrintVector(int dataVector[], int totalElements) {
  for (int i = 0; i < totalElements; i++) {
    printf("[%d]", dataVector[i]);
  }
  printf("\n");
}

void CheckOrder(int dataVector[], int totalElements) {
  for (int i = 0; i < totalElements - 1; i++) {
    if (dataVector[i] > dataVector[i + 1]) {
      printf("\tVETOR NÃO ESTÁ ORDENADO.\n");
      return;
    }
  }
  printf("\tVETOR ORDENADO COM SUCESSO.\n");
  return;
}