#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* make2dArray(int rows, int cols) {

	int** arr = (int**)malloc(sizeof(int) * rows);
	srand((int)time(NULL));
	for (int i = 0; i < rows; i++) {
		arr[i] = (int*)malloc(sizeof(int) * cols);
		for (int j = 0; j < cols; j++) {
			arr[i][j] = rand() % 100;
		}
	}
//test
	return arr;
}



int main()
{
	int** ipp;
	int i, j, rows, cols;
	printf("이차원 배열의 행과 열의 수를 입력 하세요 : ");
	scanf("%d %d", &rows, &cols);
	ipp = make2dArray(rows, cols);
	for (i = 0; i < rows; i++) {
		if ((i % 2) == 1)
			printf("\n");
		for (j = 0; j < cols; j++)
			printf("ipp[%d][%d] =%d ", i, j, ipp[i][j]);

	}

	return 0; // break point 설정 
		free(ipp);
}