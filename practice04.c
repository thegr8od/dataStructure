#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DEGREE 101

typedef struct {
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

void poly_print(char name[], polynomial sum) {
    printf("%s = ", name);
    for (int i = sum.degree; i >= 0; i--) {
        if (i == sum.degree) {
            printf("%gx^%d", sum.coef[i], i);
        }
        else if (i == 0) {
            printf(" + %g", sum.coef[i]);
        }
        else {
            printf(" + %gx^%d", sum.coef[i], i);
        }
    }
    printf("\n"); //계수가 0일때도 그냥 출력하게 구현.dddddd
}

int main() {
    polynomial A, B, C;
    int degreeA;
    int degreeB;
    printf("<< C(x) = A(x) + B(x)>>\n");
    printf("Input the degree of items of A(x): ");
    scanf("%d", &degreeA);

    printf("Input the coefficients of A(x): ");
    for (int i = degreeA; i >= 0; i--) {
        scanf("%f", &A.coef[i]);
    }
    A.degree = degreeA;

    printf("Input the degree of items of B(x): ");
    scanf("%d", &degreeB);

    printf("Input the coefficients of B(x): ");


    for (int i = degreeB; i >= 0; i--) {
        scanf("%f", &B.coef[i]);
    }
    B.degree = degreeB;

    int max_degree;
    if (degreeA > degreeB) {
        max_degree = degreeA;
    }
    else {
        max_degree = degreeB;
    }

    C.degree = max_degree;
    for (int i = max_degree; i >= 0; i--) {
        if (i <= degreeA) {
            C.coef[i] = A.coef[i];
        }
        else {
            C.coef[i] = 0;
        }
        if (i <= degreeB) {
            C.coef[i] += B.coef[i];
        }
    }

    poly_print("A(x)", A);
    poly_print("B(x)", B);
    poly_print("C(x)", C);

    return 0;
}