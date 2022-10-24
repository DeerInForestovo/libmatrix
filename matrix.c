/**
 * @file
 * @brief Functions in matrix.h is implement here.
 * @author DeerInForest[https://github.com/sustechkl]
*/

#include "matrix.h"

#include <string.h> // memset, memcpy
#include <stdlib.h> // malloc, free

#ifdef _MATRIX_LIBRARY

inline struct matrix *createMatrix(int r, int c) {
    struct matrix *mat = (struct matrix *)malloc(sizeof(struct matrix));
    mat->arr = (float *)malloc(sizeof(float) * r * c);
    if(mat->arr == NULL) { // Failed to create.
        free(mat);
        return NULL;
    } else {
        mat->row = r;
        mat->column = c;
        return mat;
    }
}

inline void clearMatrix(struct matrix *const mat) {
    if(mat != NULL) memset(mat->arr, 0, sizeof(float) * mat->row * mat->column);
}

inline struct matrix *createZeroMatrix(int r, int c) {
    struct matrix *mat = createMatrix(r, c);
    clearMatrix(mat);
    return mat;
}

inline struct matrix *createIdenticalMatrix(int r) {
    struct matrix *mat = createMatrix(r, r);
    if(mat != NULL) {
        clearMatrix(mat);
        int i;
        for(i = 1; i <= r; ++i) setMatrixElement(mat, i, i, 1);
    }
    return mat;
}

inline int deleteMatrix(struct matrix *const mat) {
    if(mat == NULL) return 1;
    if(mat->arr != NULL) free(mat->arr);
    free(mat);
    return 0;
}

inline float getMatrixElement(const struct matrix * mat, int r, int c) {
    if(mat == NULL) return 0;
    if(mat->row < r || mat->column < c) return 0;
    return mat->arr[(r - 1) * mat->column + (c - 1)];
}

inline int setMatrixElement(struct matrix *const mat, int r, int c, float val) {
    if(mat == NULL) return 1;
    if(mat->row < r || mat->column < c) return 1;
    mat->arr[(r - 1) * mat->column + (c - 1)] = val;
    return 0;
}

inline int copyMatrix(struct matrix *const targetedMat, const struct matrix *originalMat) {
    if(originalMat == NULL) return 1;
        else {
            if(targetedMat->arr == NULL) return 1;
            targetedMat->row = originalMat->row;
            targetedMat->column = originalMat->column;
            /**
             * @note
             * You can not use deleteMatrix and createMatrix here. Because the pointer 
             * targetedMat will not change outside the function, you must keep the
             * pointer targetedMat unmodified.
            */
            free(targetedMat->arr);
            targetedMat->arr = malloc(sizeof(float) * targetedMat->row * targetedMat->column);
            memcpy(targetedMat->arr, originalMat->arr, sizeof(float) * targetedMat->row * targetedMat->column);
            return 0;
        }
}

inline struct matrix *addMatrix(const struct matrix *mat1, const struct matrix *mat2) {
    if(mat1 == NULL || mat2 == NULL) return NULL;
    if(mat1->row != mat2->row || mat1->column != mat2->column) return NULL;
    struct matrix *mat = createMatrix(mat1->row, mat1->column);
    int i, _i = mat1->row * mat1->column;
    for(i = 0; i < _i; ++i) mat->arr[i] = mat1->arr[i] + mat2->arr[i];
    return mat;
}

inline struct matrix *subtractMatrix(const struct matrix *mat1, const struct matrix *mat2) {
    if(mat1 == NULL || mat2 == NULL) return NULL;
    if(mat1->row != mat2->row || mat1->column != mat2->column) return NULL;
    struct matrix *mat = createMatrix(mat1->row, mat1->column);
    int i, _i = mat1->row * mat1->column;
    for(i = 0; i < _i; ++i) mat->arr[i] = mat1->arr[i] - mat2->arr[i];
    return mat;
}

inline void addScalar(struct matrix *const mat, float val) {
    if(mat != NULL) {
        int i, _i = mat->row * mat->column;
        for(i = 0; i < _i; ++i) mat->arr[i] += val;
    }
}

inline void subtractScalar(struct matrix *const mat, float val) {
    if(mat != NULL) {
        int i, _i = mat->row * mat->column;
        for(i = 0; i < _i; ++i) mat->arr[i] -= val;
    }
}

inline void multiplyScalar(struct matrix *const mat, float val) {
    if(mat != NULL) {
        int i, _i = mat->row * mat->column;
        for(i = 0; i < _i; ++i) mat->arr[i] += val;
    }
}

inline struct matrix *multiplyMatrix(const struct matrix *mat1, const struct matrix *mat2) {
    if(mat1 == NULL || mat2 == NULL) return NULL;
    if(mat1->column != mat2->row) return NULL;
    int i, j, k;
    struct matrix *mat = createMatrix(mat1->row, mat2->column);
    for(i = 1; i <= mat1->row; ++i)
        for(j = 1; j <= mat2->column; ++j) {
            float sum = 0;
            for(k = 1; k <= mat1->column; ++k)
                sum += getMatrixElement(mat1, i, k) * getMatrixElement(mat2, k, j);
            setMatrixElement(mat, i, j, sum);
        }
    return mat;
}

inline float findMinimal(const struct matrix *mat) {
    if(mat == NULL) return 0;
    float _min = mat->arr[0];
    int i, _i = mat->row * mat->column;
    for(i = 1; i < _i; ++i) if(mat->arr[i] < _min) _min = mat->arr[i];
    return _min;
}

inline float findMaximal(const struct matrix *mat) {
    if(mat == NULL) return 0;
    float _max = mat->arr[0];
    int i, _i = mat->row * mat->column;
    for(i = 1; i < _i; ++i) if(mat->arr[i] > _max) _max = mat->arr[i];
    return _max;
}

// Additional functions

/**
 * @brief Calculate the rank of the matrix.
 * @param mat Pointer to the matrix.
 * @return The rank of the matrix.
 * @remark Number between -1e-7 and 1e-7 will be consider to be 0, so it can be wrong.
*/
inline int rank(const struct matrix *mat);

/**
 * @brief Calculate the determinant of the matrix.
 * @param mat Pointer to the matrix.
 * @return The determinant of the matrix.
 * @remark The result can be wrong when the number is too big. Use it for small matrices only.
*/
inline float determinant(const struct matrix *mat);


#endif