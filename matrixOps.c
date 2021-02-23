#include "matrixops.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum { ndi
	clockWise = -1,
	counterClockWise = 1,
}direction;

void rotateMatrixClockWise(int **arr, int row, int column){ 
	int num1, num2;
	int *p1 = &num1;
	int *p2 = &num2;
	*p1 = *(*(arr + 0) + 0);

	int i;
	for(i = 0; i < column - 1; i++){
		*p2 = *(*(arr + 0) + (i + 1));
		*(*(arr + 0) + (i + 1)) = *p1;
		*p1 = *p2;
	}

	for(i = 0; i < row - 1; i++){
		*p2 = *(*(arr + (i + 1)) + (column - 1));
		*(*(arr + (i + 1)) + (column - 1)) = *p1;
		*p1 = *p2;
	}

	for(i = column - 2; i >= 0; i--){
		*p2 = *(*(arr + (row - 1)) + i);
		 *(*(arr + (row - 1)) + i) = *p1;
		 *p1 = *p2;
		
	}

	for(i = row - 1; i > 0; i--){
		*p2 = *(*(arr + (i - 1)) + 0);
		*(*(arr + (i - 1)) + 0) = *p1;
		*p1 = *p2;
	}

	
}

void rotateMatrixCounterClockWise(int **arr, int row, int column){
	int num1, num2;
	int *p1 = &num1;
	int *p2 = &num2;
	*p1 = *(*(arr + 0) + 0); 
	int i;
	for(i = 0; i < row - 1; i++){
		*p2 = *(*(arr + (i + 1)) + 0);
		*(*(arr + (i + 1)) + 0) = *p1;
		*p1 = *p2;
	}
	for(i = 0; i < column - 1; i++){
		*p2 = *(*(arr + (row - 1)) + (i + 1));
		*(*(arr + (row - 1)) + (i + 1)) = *p1;
		*p1 = *p2;
	}

	for(i = row - 1; i > 0; i--){
		*p2 = *(*(arr + (i - 1)) + (column - 1));
		*(*(arr + (i - 1)) + (column - 1)) = *p1;
		*p1 = *p2;
	}
	for(i = column - 2; i >= 0; i--){
		*p2 = *(*(arr + 0) + i);
		*(*(arr + 0) + i) = *p1;
		*p1= *p2;
	}

}

void rotateMatrix(int **arr, int row, int column, direction d, int stepNumber){
	if(d == clockWise){/
		int i;
		for(i = 0; i < stepNumber; i++){
			rotateMatrixClockWise(arr, row, column); 

	} else if(d == counterClockWise){
		int i;
		for(i = 0; i < stepNumber; i++){
			rotateMatrixCounterClockWise(arr, row, column); 
		}
		
	}
}

void printMatrix(int **arr, int row, int column){
	int i, j; 
    for (i = 0; i < row; i++) {
    	for (j = 0; j < column; j++) {
    		printf("%d\t", *(*(arr + i) + j));
		}
        printf("\n");
	}
}

int** crate2DMatrix(int row, int column, int maxNumber){ 
	int **arr = (int **) malloc(row * sizeof(int *));
	int i;
	for (i = 0; i < row; i++) {
		*(arr + i) = (int *) malloc(column * sizeof(int)); 
    srand(time(NULL));
    for (i = 0; i < row; i++) {
    	int j;
    	for (j = 0; j < column; j++) {
      		*(*(arr + i) + j) = (rand() % (maxNumber + 1));
	    }
	}
      
	return arr;
}

void deleteHeap(int **arr, int numberOfArrays){ 
	int i;
	for(i = 0; i < numberOfArrays; i++){
		free(*(arr + i));
	}
	free(arr);
}