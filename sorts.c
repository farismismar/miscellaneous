#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int bubble_sort(int array[], int size)
{
  int mem_access = 0;

  int i = 0;
  int j = 0;
  for (i = 0; i < size; i++)
    for (j = 0; j < size - i - 1; j++)
      if (array[j] > array[j+1]) {
        swap(&array[j], &array[j+1]);
        mem_access += 4;
     }

  return mem_access;
}

int insertion_sort(int array[], int size)
{
  int mem_access = 0;

  int i = 0;
  int j = 0;
  int current = 0;

  for (i = 1; i < size; i++) {
    /* the current position */
    current = array[i];
    mem_access++;
    j = i - 1;

    /* create space for the element's correct position */
    while ((j >= 0) && (array[j] > current)) {
      array[j + 1] = array[j];
      mem_access += 2;
      j--;
    }

    array[j + 1] = current;
    mem_access++;
  }

  return mem_access;
}

void printArr(int array[], int size)
{
  int i = 0;
  printf("[%d", array[i]);

  for (i = 1; i < size; i++)
    printf(",%d", array[i]);

  printf("]");
}

int main()
{
  int array[] = {1, 5, 4, 0, 313, 7};
  printArr(array, 6);
  printf("\n");
  int perf = insertion_sort(array, 6);
  printf("Insertion sort required %d memory accesses.\n", perf);
  printArr(array, 6);
  printf("\n");

  return 0;
}

