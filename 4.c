#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 101

int pmatch(char* string, char* pat, int* failure);

int main()
{
    char string[MAX_LENGTH];
    char pat[MAX_LENGTH];
    int failure[MAX_LENGTH];

    printf("문자열을 입력하세요 : ");
    scanf("%s", string);

    printf("비교할 패턴을 입력하세요 : ");
    scanf("%s", pat);

    int lenp = strlen(pat);
    failure[0] = -1;

    for (int i = 1, j = -1; i < lenp; i++) {
        while (j >= 0 && pat[j + 1] != pat[i])
            j = failure[j];
        if (pat[j + 1] == pat[i])
            j++;
        failure[i] = j;
    }

    printf("pat의 위치 정보 값\n");
    int i = 0;
    for (i; i < lenp; i++) {
        printf("failure[%d]=%5d  ", i, failure[i]);
        if (i > 3 && i % 5 == 4) {
            printf("\n");
        }
    }

    int compare = pmatch(string, pat, failure);

    if (compare >= 0) {
        printf("문자열 %d 번째부터 패턴이 시작됨..", compare);
    }
    else {
        printf("패턴이 없습니다.");
    }

    return 0;
}

int pmatch(char* string, char* pat, int* failure)
{
    int i = 0, j = 0;
    int lens = strlen(string);
    int lenp = strlen(pat);
    while (i < lens && j < lenp) {
        if (string[i] == pat[j]) {
            i++;
            j++;
        }
        else if (j == 0) {
            i++;
        }
        else {
            j = failure[j - 1] + 1;
        }
    }
    return ((j == lenp) ? (i - lenp) : -1);
}