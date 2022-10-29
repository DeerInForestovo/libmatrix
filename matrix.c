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
    mat->__arr = (float *)malloc(sizeof(float) * r * c);
    if(mat->__arr == NULL) { // Failed to create.
        free(mat);
        return NULL;
    } else {
        mat->__row = r;
        mat->__column = c;
        return mat;
    }
}

inline void clearMatrix(struct matrix *const mat) {
    if(mat != NULL) memset(mat->__arr, 0, sizeof(float) * mat->__row * mat->__column);
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
    if(mat->__arr != NULL) free(mat->__arr);
    free(mat);
    return 0;
}

inline float getMatrixElement(const struct matrix * mat, int r, int c) {
    if(mat == NULL) return 0;
    if(mat->__row < r || mat->__column < c) return 0;
    return mat->__arr[(r - 1) * mat->__column + (c - 1)];
}

inline int setMatrixElement(struct matrix *const mat, int r, int c, float val) {
    if(mat == NULL) return 1;
    if(mat->__row < r || mat->__column < c) return 1;
    mat->__arr[(r - 1) * mat->__column + (c - 1)] = val;
    return 0;
}

inline int copyMatrix(struct matrix *const targetedMat, const struct matrix *originalMat) {
    if(originalMat == NULL || targetedMat == NULL) return 1;
        else {
            if(originalMat->__arr == NULL) return 1;
            targetedMat->__row = originalMat->__row;
            targetedMat->__column = originalMat->__column;
            /**
             * @note
             * You can not use deleteMatrix and createMatrix here. Because the pointer 
             * targetedMat will not change outside the function, you must keep the
             * pointer targetedMat unmodified.
            */
            if(targetedMat->__arr != NULL) free(targetedMat->__arr);
            targetedMat->__arr = (float *)malloc(sizeof(float) * targetedMat->__row * targetedMat->__column);
            memcpy(targetedMat->__arr, originalMat->__arr, sizeof(float) * targetedMat->__row * targetedMat->__column);
            return 0;
        }
}

inline struct matrix *addMatrix(const struct matrix *mat1, const struct matrix *mat2) {
    if(mat1 == NULL || mat2 == NULL) return NULL;
    if(mat1->__row != mat2->__row || mat1->__column != mat2->__column) return NULL;
    struct matrix *mat = createMatrix(mat1->__row, mat1->__column);
    int i, _i = mat1->__row * mat1->__column;
    for(i = 0; i < _i; ++i) mat->__arr[i] = mat1->__arr[i] + mat2->__arr[i];
    return mat;
}

inline struct matrix *subtractMatrix(const struct matrix *mat1, const struct matrix *mat2) {
    if(mat1 == NULL || mat2 == NULL) return NULL;
    if(mat1->__row != mat2->__row || mat1->__column != mat2->__column) return NULL;
    struct matrix *mat = createMatrix(mat1->__row, mat1->__column);
    int i, _i = mat1->__row * mat1->__column;
    for(i = 0; i < _i; ++i) mat->__arr[i] = mat1->__arr[i] - mat2->__arr[i];
    return mat;
}

inline void addScalar(struct matrix *const mat, float val) {
    if(mat != NULL) {
        int i, _i = mat->__row * mat->__column;
        for(i = 0; i < _i; ++i) mat->__arr[i] += val;
    }
}

inline void subtractScalar(struct matrix *const mat, float val) {
    if(mat != NULL) {
        int i, _i = mat->__row * mat->__column;
        for(i = 0; i < _i; ++i) mat->__arr[i] -= val;
    }
}

inline void multiplyScalar(struct matrix *const mat, float val) {
    if(mat != NULL) {
        int i, _i = mat->__row * mat->__column;
        for(i = 0; i < _i; ++i) mat->__arr[i] *= val;
    }
}

inline struct matrix *multiplyMatrix(const struct matrix *mat1, const struct matrix *mat2) {
    if(mat1 == NULL || mat2 == NULL) return NULL;
    if(mat1->__column != mat2->__row) return NULL;
    int i, j, k;
    struct matrix *mat = createMatrix(mat1->__row, mat2->__column);
    for(i = 1; i <= mat1->__row; ++i)
        for(j = 1; j <= mat2->__column; ++j) {
            float sum = 0;
            for(k = 1; k <= mat1->__column; ++k)
                sum += getMatrixElement(mat1, i, k) * getMatrixElement(mat2, k, j);
            setMatrixElement(mat, i, j, sum);
        }
    return mat;
}

inline float findMinimal(const struct matrix *mat) {
    if(mat == NULL) return 0;
    float _min = mat->__arr[0];
    int i, _i = mat->__row * mat->__column;
    for(i = 1; i < _i; ++i) if(mat->__arr[i] < _min) _min = mat->__arr[i];
    return _min;
}

inline float findMaximal(const struct matrix *mat) {
    if(mat == NULL) return 0;
    float _max = mat->__arr[0];
    int i, _i = mat->__row * mat->__column;
    for(i = 1; i < _i; ++i) if(mat->__arr[i] > _max) _max = mat->__arr[i];
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