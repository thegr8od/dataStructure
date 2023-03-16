#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
	FILE* fp1;
	FILE* fp2;
	int arr1[20] = { 0, };
	int arr2[20] = { 0, };


	int i = 0;


	fp1 = fopen("input-1.txt", "r");

	while (fscanf(fp1, "%d", &arr1[i]) != EOF)
	{

		i++;
	}

	fp2 = fopen("input-2.txt", "r");

	int j = 0;

	while (fscanf(fp2, "%d", &arr2[j]) != EOF)
	{

		j++;
	}

	for (int j = 0; j < 10; j++) {
		printf("%3d,", arr1[j]);
	}
	printf("\n");

	for (int j = 0; j < 10; j++) {
		printf("%3d,", arr2[j]);
	}
	printf("\n");
	for (int j = 0; j < 10; j++) {
		printf("%3d,", arr1[j] + arr2[j]);
	}


	fclose(fp1);
	fclose(fp2);

	return 0;

}