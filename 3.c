#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>



typedef struct student
{
	int height;
	int weight;
	char name[30];
	double BMI;
}student;

int main(void)
{
	FILE* fp;
	student a[10] = { 0, };
	int i = 0;


	fp = fopen("input.txt", "r");

	while (fscanf(fp, "%d %d %s", &a[i].height, &a[i].weight, a[i].name) != EOF)
	{

		a[i].BMI = ((double)a[i].weight / (double)(a[i].height * a[i].height)) * 10000;
		i++;
	}


	double pBMI = 0;
	printf("BMI 값을 쓰시오 : ");

	scanf("%lf", &pBMI);
	printf("\n");
	printf("\n");


	printf("키\t몸무게\t이름\tBMI\n");
	printf("==================================\n");
	for (int j = 0; j < i; j++) {

		printf("%d\t%d\t%s\t%.2lf\n", a[j].height, a[j].weight, a[j].name, a[j].BMI);

	}
	printf("\n");
	printf("\n");
	double Diff = 0;
	double DiffMin = 100;
	int index = 0;
	for (int j = 0; j < i; j++)
	{
		Diff = fabs(pBMI - a[j].BMI);
		if (DiffMin > Diff) {
			DiffMin = Diff;
			index = j;
		}
	}

	printf("BMI 값이 %.2lf에 가장 근접한 사람 : \n", pBMI);
	printf("키 : %d, 몸무게 : %d, 이름 : %s, BMI : %.2lf", a[index].height, a[index].weight, a[index].name, a[index].BMI);
	fclose(fp);
}