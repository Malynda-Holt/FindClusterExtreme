#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"


/*This function takes an array of unsorted floats and the size of the array,
and returns the lower value of the widest seperated pair of floats.
Runtime: O(N)*/
float findClusterExtreme(float array[], int n) {

	float min = array[0];
	float max = array[0];

	//Initializing buckets
	float * bucketArr = malloc(sizeof(float) * (n - 2));

	for (int i = 0; i < (n - 2); i++) {
		bucketArr[i] = 0.0;
	}

	
	//Identifying min and max values in array
	for (int i = 0; i < n; i++) {
		
		if(min > array[i]){
			min = array[i];
		}
		
		if (max < array[i]) {
			max = array[i];
		}

	}


	//Variables for caluclating element indecies
	int index;
	float ratio;


	for (int i = 0; i < (n - 1); i++) {

		if (array[i] == min || array[i] == max) {
		//Do nothing. Min and Max values not put into new array.
		}

		else {
			//Calculate index
			ratio = (array[i] - min) / (max - min);
			index = ratio * (n-2);
		
			if (bucketArr[index] == 0.0) {
				bucketArr[index] = array[i];
			}

		}

	}


	//Hold count represents the number of empty buckets in the current gap the for loop has identified
	int holdCount = 0;

	//Hold value represents the last non-empty bucket value
	float holdValue;

	//Pairvalue is the current lowest element in the widest seperated pair of elements
	float pairValue = bucketArr[0];

	//Empty count is the current largest gap between buckets.
	//Empty count is compared with holdCount to determine if the recorded largest gap needs to
	//be replaced by the current gap
	int emptyCount = 0;


	//Iterate through bucket array 
	//O(N) runtime
	for (int i = 0; i < (n - 2); i++) {

		//If data isnt 0, set hold value to array[i];
		if (bucketArr[i] != 0) {
			holdCount = 0;
			holdValue = bucketArr[i];

		}
		//If data is zero, add 1 to hold count
		else {
			holdCount++;
			

			//If current holdcount is larger than emptyCount
			//Set emptyCount to holdCount
			//Replace pairValue with holdValue
			//Set pairValue to 0
			if (holdCount > emptyCount) {
				emptyCount = holdCount;
				pairValue = holdValue;
				holdCount = 0;
			}

		}

	}


	free(bucketArr);
	

	return(pairValue);


}


/*https://www.geeksforgeeks.org/c-bubble-sort/*/
//Bubble sort algorithm from geeksforgeeks
//Time complexity: O(N^2)

void swap(float * arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


void bubbleSort(float arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already 
		// in place 
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr, j, j + 1);
}


//Merge sort algorithm
//TIme complexity O(N log(N))
//https://www.geeksforgeeks.org/c-program-for-merge-sort/
void merge(float arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(float arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}
