#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    char arr[200];
    printf("���ڿ��� �Է� : ");
    gets(arr);

    for (int i = 0; arr[i] != '\0'; i++) {
        if (islower(arr[i])) {
            if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
                arr[i] = arr[i];
            }
            else {
                arr[i] = toupper(arr[i]);
            }
        }
    }


    printf("������ �빮�ڷ� ��ȯ ��� : %s", arr);

    return 0;
}