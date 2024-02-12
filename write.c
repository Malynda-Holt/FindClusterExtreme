#include <stdio.h>

int main(void) {

	//Change N to desired limit
	int n = 1000;


	FILE* fptr;
	fptr = fopen("sequence2.txt", "w");

	for (int i = 0; i < n; i++) {
		fprintf(fptr, "%d\n", i);
	}


	fclose(fptr);

}