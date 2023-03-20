#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101
#define MAX_COL 101

typedef struct {
    int row;
    int col;
    int value;
} term;

void printSparseMatrix(term a[], int numRows, int numCols) {
    int i, j, index = 1;

    for (i = 0; i < numRows; i++) {

        for (j = 0; j < numCols; j++) {

            if (a[index].row == i && a[index].col == j) {
                printf("%4d ", a[index].value);
                index++;
            }
            else {
                printf("%4d ", 0);
            }
        }
        printf("\n");
    }
}

void fastTranspose(term a[], term b[]) {
    int rowTerms[MAX_COL], startingPos[MAX_COL];
    int i, j, numCols = a[0].col, numTerms = a[0].value;
    b[0].row = numCols;
    b[0].col = a[0].row;
    b[0].value = numTerms;
    if (numTerms > 0) {
        for (i = 0; i < numCols; i++) {
            rowTerms[i] = 0;
        }
        for (i = 1; i <= numTerms; i++) {
            rowTerms[a[i].col]++;
        }
        startingPos[0] = 1;
        for (i = 1; i < numCols; i++) {
            startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
        }
        for (i = 1; i <= numTerms; i++) {
            j = startingPos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}

int main() {
    FILE* input_file, * output_file;
    char inputfile[] = "a.txt";
    char outputfile[] = "b.txt";

    int numRows, numCols, numTerms, i;
    term a[MAX_TERMS], b[MAX_TERMS];
    input_file = fopen(inputfile, "r");
    fscanf(input_file, "%d %d %d", &numRows, &numCols, &numTerms);

    a[0].row = numRows;
    a[0].col = numCols;
    a[0].value = numTerms;

    for (i = 1; i <= numTerms; i++) {
        fscanf(input_file, "%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    }

    fclose(input_file);

    fastTranspose(a, b);

    output_file = fopen(outputfile, "w");
    fprintf(output_file, "%d %d %d\n", numRows, numCols, numTerms);

    for (i = 1; i <= numTerms; i++) {
        fprintf(output_file, "%d %d %d\n", b[i].row, b[i].col, b[i].value);
    }
    fclose(output_file);

    printf("A\n");
    printSparseMatrix(a, numRows, numCols);
    printf("\nB\n");
    printSparseMatrix(b, numCols, numRows);

    return 0;
}