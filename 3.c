#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int nfind(char* string, char* pat) {
    int i = 0, j = 0, start = 0;
    int lasts = strlen(string) - 1;
    int lastp = strlen(pat) - 1;
    int endmatch = lastp;

    for (i = 0; endmatch <= lasts; endmatch++, start++) {
        if (string[endmatch] == pat[lastp]) {
            for (j = 0, i = start; j < lastp && string[i] == pat[j]; i++, j++);
            if (j == lastp) {
                return start; 
            }
        }
    }
    return -1;
}

int main() {
    char string[100], pat[100];

    printf("���ڿ��� �Է��ϼ���: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';  //string���� ù ��° ���� ǥ�ø� ã��

    printf("���� ������ �Է��ϼ���: ");
    fgets(pat, sizeof(pat), stdin);
    pat[strcspn(pat, "\n")] = '\0'; 

    int index = nfind(string, pat);

    if (index == -1) {
        printf("������ �����ϴ�.\n");
    }
    else {
        printf("���ڿ� %d ��°���� ������ ���۵�..\n", index);
    }

    return 0;
}