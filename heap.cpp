#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void heapSort(int numbers[], int array_size);
void siftDown(int numbers[], int root, int bottom);

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
		//perform heap sort on array
		heapSort(numbers, NUM_ITEMS);
		
		finish = clock();
		printf("Size is: %d\n", NUM_ITEMS);
		printf("Average Time: %3f\n", (double)(finish - start) / CLOCKS_PER_SEC * 1000);			

		delete [] numbers;
	}

	return 0;
}


void heapSort(int numbers[], int array_size)
{
	int i, temp;
	
	for (i = (array_size / 2)-1; i >= 0; i--)
		siftDown(numbers, i, array_size);
	
	for (i = array_size-1; i >= 1; i--)
	{
		temp = numbers[0];
		numbers[0] = numbers[i];
		numbers[i] = temp;
		siftDown(numbers, 0, i-1);
	}
}


void siftDown(int numbers[], int root, int bottom)
{
	int done, maxChild, temp;
	
	done = 0;
	while ((root*2 <= bottom) && (!done))
	{
		if (root*2 == bottom)
			maxChild = root * 2;
		else if (numbers[root * 2] > numbers[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		
		if (numbers[root] < numbers[maxChild])
		{
			temp = numbers[root];
			numbers[root] = numbers[maxChild];
			numbers[maxChild] = temp;
			root = maxChild;
		}
		else
			done = 1;
	}
}
