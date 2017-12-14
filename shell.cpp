#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void shellSort(int numbers[], int array_size);

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
		//perform shell sort on array
		shellSort(numbers, NUM_ITEMS);

		
		finish = clock();
		printf("Size is: %d\n", NUM_ITEMS);
		printf("Average Time: %3f\n", (double)(finish - start) / CLOCKS_PER_SEC * 1000);			

		delete [] numbers;
	}

	return 0;
}

void shellSort(int numbers[], int array_size)
{
  int i, j, increment, temp;

  increment = 3;
  while (increment > 0)
  {
    for (i=0; i < array_size; i++)
    {
      j = i;
      temp = numbers[i];
      while ((j >= increment) && (numbers[j-increment] > temp))
      {
        numbers[j] = numbers[j - increment];
        j = j - increment;
      }
      numbers[j] = temp;
    }
    if (increment/2 != 0)
      increment = increment/2;
    else if (increment == 1)
      increment = 0;
    else
      increment = 1;
  }
}


