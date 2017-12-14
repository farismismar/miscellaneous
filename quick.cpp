#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void quickSort(int numbers[], int array_size);
void q_sort(int numbers[], int left, int right);

int main()
{
	int i;
	int j;

	int NUM_ITEMS;

	clock_t start, finish;

	//seed random number generator
	srand(time(NULL));
	
	for (j = 0; j < 10; j++) {
		NUM_ITEMS = j * 10000;
		
		int *numbers = new int [NUM_ITEMS];
		
		//fill array with random integers
		for (i = 0; i < NUM_ITEMS; i++)
			numbers[i] = rand();
		
		start = clock();
		//perform quick Sort on array
		quickSort(numbers, NUM_ITEMS);

		
		finish = clock();
		printf("Size is: %d\n", NUM_ITEMS);
		printf("Average Time: %3f\n", (double)(finish - start) / CLOCKS_PER_SEC * 1000);			

		delete [] numbers;
	}

	return 0;
}

void quickSort(int numbers[], int array_size)
{
  q_sort(numbers, 0, array_size - 1);
}



void q_sort(int numbers[], int left, int right)
{
  int pivot, l_hold, r_hold;

  l_hold = left;
  r_hold = right;
  pivot = numbers[left];
  while (left < right)
  {
    while ((numbers[right] >= pivot) && (left < right))
      right--;
    if (left != right)
    {
      numbers[left] = numbers[right];
      left++;
    }
    while ((numbers[left] <= pivot) && (left < right))
      left++;
    if (left != right)
    {
      numbers[right] = numbers[left];
      right--;
    }
  }
  numbers[left] = pivot;
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot)
    q_sort(numbers, left, pivot-1);
  if (right > pivot)
    q_sort(numbers, pivot+1, right);
}
