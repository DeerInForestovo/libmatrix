/**
 * @file
 * @brief A tester for matrix.h.
 * @author DeerInForest[https://github.com/sustechkl]
 * 
 * The library can be used without this tester.
*/

#include "matrix.h"

#include <stdio.h>

#ifdef _MATRIX_LIBRARY

float A[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

float B[3][4] = {
    {1, 1, 1, 1},
    {2, 3.5, 4.5, 5.5},
    {-1, -2, -3, -4}
};

inline void printMatrix(struct matrix *mat) {
    if(mat != NULL) {
        int r = getMatrixRowNumber(mat), c = getMatrixColumnNumber(mat);
        int i, j;
        for(i = 1; i <= r; ++i) {
            for(j = 1; j <= c; ++j)
                printf("%.2f ", getMatrixElement(mat, i, j));
            printf("\n");
        }
    } else printf("ERROR: matrix pointer is null.\n");
}

int main() {
    int i, j;
    struct matrix *matA = createMatrix(3, 3);
    for(i = 0; i < 3; ++i)
        for(j = 0; j < 3; ++j)
            setMatrixElement(matA, i + 1, j + 1, A[i][j]);
    struct matrix *matB = createMatrix(3, 4);
    for(i = 0; i < 3; ++i)
        for(j = 0; j < 4; ++j)
            setMatrixElement(matB, i + 1, j + 1, B[i][j]);
    struct matrix *matC = createIdenticalMatrix(3);
    struct matrix *matD = createZeroMatrix(3, 3);
    printf("matrix A is:\n");
    printMatrix(matA);
    printf("matrix B is:\n");
    printMatrix(matB);
    printf("matrix C is:\n");
    printMatrix(matC);
    printf("matrix D is:\n");
    printMatrix(matD);
    addScalar(matA, 3);
    printf("matrix A = A + 3 is:\n");
    printMatrix(matA);
    subtractScalar(matA, 3);
    printf("matrix A = A - 3 is:\n");
    printMatrix(matA);
    multiplyScalar(matA, 3);
    printf("matrix A = A * 3 is:\n");
    printMatrix(matA);
    addMatrix(matA, matC);
    printf("matrix A = A + C is:\n");
    printMatrix(matA);
    subtractMatrix(matA, matC);
    printf("matrix A = A - C is:\n");
    printMatrix(matA);
    multiplyMatrix(matA, matB);
    printf("matrix A = A * B is:\n");
    printMatrix(matA);
    struct matrix *matH = createMatrix(1, 1);
    copyMatrix(matH, matA);
    printf("matrix H = A is:\n");
    printMatrix(matH);
    printf("min in H is %.2f\n", findMinimal(matH));
    printf("max in H is %.2f\n", findMaximal(matH));
    printf("row number of H is %d\n", getMatrixRowNumber(matH));
    printf("column number of H is %d\n", getMatrixColumnNumber(matH));
    clearMatrix(matH);
    printf("matrix H = 0 is:\n");
    printMatrix(matH);
    printf("Is matA exists? %d\n", __checkMatrix(matA));
    deleteMatrix(matA);
    printf("Is matA exists? %d\n", __checkMatrix(matA));
    printf("Is matB exists? %d\n", __checkMatrix(matB));
    deleteAllMatrices();
    printf("Is matB exists? %d\n", __checkMatrix(matB));
    return 0;
}

#endif