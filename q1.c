#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int* func1() {
	int* pi = (int*)malloc(sizeof(int*));
	*pi = 10;

	return pi;
}

void func2(int* pi) {
	*pi = 100;
}

void func3(int** ppi) {
	**ppi = 200;
}

char* func4(int size) {
	char* pChar = (char*)malloc(size);
	memset(pChar, 0, size);
	return pChar;
}



int main(void)
{
	int* pNum;
	char* pChar;
	pNum = func1(); // int ũ�⸸ŭ �����Ҵ� �޾� 10�� ������ ������ ������ ����
	printf("%d\n", *pNum);
	func2(pNum);// pNum�� ����Ű�� ���� 100���� ����
	printf("%d\n", *pNum);
	func3(&pNum); // pNum�� ����Ű�� ���� 200���� ����
	printf("%d\n\n", *pNum);
	pChar = func4(100); // pChar �� 100byte �Ҵ� ���� �޸𸮿� Ű����κ��� 
	//�Է� ���� ���ڿ� ����
	printf("�Է��� ���ڿ� : ");
	scanf("%s", pChar);
	printf("pChar contents = %s\n", pChar);
	free(pNum);
	free(pChar);


	return 0;
}
