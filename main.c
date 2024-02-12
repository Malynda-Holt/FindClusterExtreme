#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"


int main(void) {



	FILE* fptr;
	fptr = fopen("sequence6.txt", "r");


	int size = 0;
	float holdElement;

	//Retrieve number of elements in file
	while (!feof(fptr)) {
		fscanf(fptr, "%f\n", &holdElement);
		size += 1;

	}

	printf("File successfully read, Last Element: %f\n", holdElement);

	//Close file
	fclose(fptr);

	float* array = malloc(sizeof(float) * size); //Initializing sequence array with determined dataset size
	
	//File is reopened to populate sequence array with dataset.
	FILE* f;
	f = fopen("sequence6.txt", "r");

	//Read file into array
	for (int i = 0; i < size; i++) {

		fscanf(fptr, "%f\n", &array[i]);

	}

	fclose(f);

	//Shuffling array because array needs to be unsorted
	srand(time(NULL));
	for (int i = (size - 1); i > 0; i--) {
		int j = rand() % (i + 1);


		int temp = *(array + i);
		*(array + i) = *(array + j);
		*(array + j) = temp;
	}

	printf("SIZE: %d\n", size);

	clock_t start, end;
	double runtime;

	start = clock();
	 /* Do the work. */
	float value = findClusterExtreme(array, size);
	end = clock();
	runtime = ((double)(end - start));


	//loat value = findClusterExtreme(array, size);
	printf("Lower value of widest pair: %f\n", value);
	printf("findClusterExtreme: %lf\n", runtime);


	start = clock();
	
	bubbleSort(array, size);

	end = clock();
	runtime = ((double)(end - start));
	printf("bubbleSort: %lf\n", runtime);



	//Shuffling array because array needs to be unsorted
	srand(time(NULL));
	for (int i = (size - 1); i > 0; i--) {
		int j = rand() % (i + 1);


		int temp = *(array + i);
		*(array + i) = *(array + j);
		*(array + j) = temp;
	}



	start = clock();

	mergeSort(array, 0, size-1);

	end = clock();
	runtime = ((double)(end - start));
	printf("mergeSort: %lf\n", runtime);

	free(array);


	



}


