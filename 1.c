#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int arr[21][21];

void* make2dArray(int num) {
	int i;
	int j;
	int ranR = 0;
	int ranB = 0;
	srand((int)time(NULL));

	for (i = 0; i < num; i++) {
		int rows = rand() % 20;
		int cols = rand() % 20;

		if (ranR == rows && ranB == cols) {
			i--;
		}

		ranR = rows;
		ranB = cols;

		arr[rows][cols] = rand() % 100;


	}

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
}



int main()
{

	int n = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			arr[i][j] = 0;
		}
	}

	printf("원소의 개수를 쓰시오 .. ");
	scanf("%d", &n);
	printf("Random generated Matrix(20,20)\n");
	make2dArray(n);
	printf("space matrix\n");
	printf("%4d, %4d %4d\n", 20,20,7);
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (arr[i][j] != 0) {
				printf("%4d, %4d %4d\n", i, j, arr[i][j]);
			}
		}
	}

	return 0;
}
