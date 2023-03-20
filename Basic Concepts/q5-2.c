#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>

#define MAX_SIZE 2001

void SwapNum(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}


void sort(int arr[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > key; j--) {
			arr[j + 1] = arr[j]; // µÚ·ÎÀÌµ¿
		}
		arr[j + 1] = key;
	}
}

void main(void)
{

	FILE* fp;
	fp = fopen("output.txt", "w");
	int i, n, step = 10;
	int a[MAX_SIZE];
	double duration;

	fprintf(fp, "   n   repetitions   time\n");
	for (n = 0; n <= 2000; n += step)
	{
		long repetitions = 0;
		clock_t start = clock();
		do
		{
			repetitions++;

			for (i = 0; i < n; i++)
				a[i] = i + 1;

			sort(a, n);
		} while (clock() - start < 1000);
		duration = ((double)(clock() - start))
			/ CLOCKS_PER_SEC;
		duration /= repetitions;
		fprintf(fp, "%6d  %9d  %f\n", n, repetitions, duration);
		if (n == 100) step = 100;
	}
	fclose(fp);
}
