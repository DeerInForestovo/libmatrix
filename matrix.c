/**
 * @file
 * @brief Functions in matrix.h is implement here.
 * @author DeerInForest[https://github.com/sustechkl]\
 * 
 * Functions in matrix.h is implement here.
 * Instead of accessing the variables in a matrix, you are recommended
 * to use these functions below.
*/

#include "matrix.h"

#include <string.h> // memset, memcpy
#include <stdlib.h> // malloc, free

#ifdef _MATRIX_LIBRARY

#define _node __matrixLinkedListNode
#define _head __matrixLinkedListHead

struct _node {
    struct _node *next;
    struct matrix *val;
};

struct _node *_head = NULL;

inline int __checkMatrix(const struct matrix *mat) {
    struct _node *now = _head;
    while(now != NULL) {
        if(now->val == mat) return 1;
        now = now->next;
    }
    return 0;
}

inline void __addMatrixNode(struct matrix *mat) {
    if(__checkMatrix(mat)) return;
    struct _node *node = (struct _node *)malloc(sizeof(struct _node));
    node->next = _head;
    node->val = mat;
    _head = node;
}

inline void __removeMatrixNode(const struct matrix *mat) {
    if(_head != NULL) {
        if(_head->val == mat) {
            struct _node *theNext = _head->next;
            free(_head);
            _head = theNext;
            return;
        }
    } else return;
    struct _node *now = _head;
    while(now != NULL) { /* while(true) */
        if(now->next != NULL) {
            if(now->next->val == mat) {
                struct _node *theNext = now->next->next;
                free(now->next);
                now->next = theNext;
                break;
            }
            now = now->next;
        } else break;
    }
}

inline struct matrix *createMatrix(int r, int c) {
    struct matrix *mat = (struct matrix *)malloc(sizeof(struct matrix));
    mat->__arr = (float *)malloc(sizeof(float) * r * c);
    if(mat->__arr == NULL) { // Failed to create.
        free(mat);
        return NULL;
    } else {
        mat->__row = r;
        mat->__column = c;
        __addMatrixNode(mat);
        return mat;
    }
}

inline void clearMatrix(struct matrix *const mat) {
    if(__checkMatrix(mat)) memset(mat->__arr, 0, sizeof(float) * mat->__row * mat->__column);
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
    if(!__checkMatrix(mat)) return 1;
    if(mat->__arr != NULL) free(mat->__arr);
    __removeMatrixNode(mat);
    free(mat);
    return 0;
}

inline void deleteAllMatrices() {
    while(_head != NULL) {
        struct _node* theNext = _head->next;
        deleteMatrix(_head->val);
        _head = theNext;
    }
}

inline int getMatrixRowNumber(const struct matrix *mat) {
    if(!__checkMatrix(mat)) return 0;
    return mat->__row;
}

inline int getMatrixColumnNumber(const struct matrix *mat) {
    if(!__checkMatrix(mat)) return 0;
    return mat->__column;
}

inline float getMatrixElement(const struct matrix *mat, int r, int c) {
    if(!__checkMatrix(mat)) return 0;
    if(mat->__row < r || mat->__column < c || r < 1 || c < 1) return 0;
    return mat->__arr[(r - 1) * mat->__column + (c - 1)];
}

inline int setMatrixElement(struct matrix *const mat, int r, int c, float val) {
    if(!__checkMatrix(mat)) return 1;
    if(mat->__row < r || mat->__column < c || r < 1 || c < 1) return 1;
    mat->__arr[(r - 1) * mat->__column + (c - 1)] = val;
    return 0;
}

inline int copyMatrix(struct matrix *const targetedMat, const struct matrix *originalMat) {
    if(!__checkMatrix(originalMat) || !__checkMatrix(targetedMat)) return 1;
        else {
            if(originalMat->__arr == NULL) return 1; // Unexpected error
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

inline struct matrix *createMatrixCopy(const struct matrix *mat) {
    struct matrix *new = createMatrix(1, 1);
    copyMatrix(new, mat);
    return new;
}

inline int addScalar(struct matrix *const mat, float val) {
    if(__checkMatrix(mat)) {
        int i, _i = mat->__row * mat->__column;
        for(i = 0; i < _i; ++i) mat->__arr[i] += val;
        return 0;
    }
    return 1;
}

inline int subtractScalar(struct matrix *const mat, float val) {
    if(__checkMatrix(mat)) {
        int i, _i = mat->__row * mat->__column;
        for(i = 0; i < _i; ++i) mat->__arr[i] -= val;
        return 0;
    }
    return 1;
}

inline int multiplyScalar(struct matrix *const mat, float val) {
    if(__checkMatrix(mat)) {
        int i, _i = mat->__row * mat->__column;
        for(i = 0; i < _i; ++i) mat->__arr[i] *= val;
        return 0;
    }
    return 1;
}

inline int addMatrix(struct matrix *const mat1, const struct matrix *mat2) {
    if(!__checkMatrix(mat1) || !__checkMatrix(mat2)) return 1;
    if(mat1->__column != mat2->__column || mat1->__row != mat2->__row) return 1;
    int i, _i = mat1->__row * mat1->__column;
    for(i = 0; i < _i; ++i) mat1->__arr[i] += mat2->__arr[i];
    return 0;
}

inline int subtractMatrix(struct matrix *const mat1, const struct matrix *mat2) {
    if(!__checkMatrix(mat1) || !__checkMatrix(mat2)) return 1;
    if(mat1->__column != mat2->__column || mat1->__row != mat2->__row) return 1;
    int i, _i = mat1->__row * mat1->__column;
    for(i = 0; i < _i; ++i) mat1->__arr[i] -= mat2->__arr[i];
    return 0;
}

inline int multiplyMatrix(struct matrix *const mat1, const struct matrix *mat2) {
    if(!__checkMatrix(mat1) || !__checkMatrix(mat2)) return 1;
    if(mat1->__column != mat2->__row) return 1;
    int i, j, k;
    struct matrix *mat = createZeroMatrix(mat1->__row, mat2->__column);
    for(i = 1; i <= mat1->__row; ++i)
        for(j = 1; j <= mat2->__column; ++j) {
            float sum = 0;
            for(k = 1; k <= mat1->__column; ++k)
                sum += getMatrixElement(mat1, i, k) * getMatrixElement(mat2, k, j);
            setMatrixElement(mat, i, j, sum);
        }
    copyMatrix(mat1, mat);
    free(mat);
    return 0;
}

inline float findMinimal(const struct matrix *mat) {
    if(!__checkMatrix(mat)) return 0;
    float _min = mat->__arr[0];
    int i, _i = mat->__row * mat->__column;
    for(i = 1; i < _i; ++i) if(mat->__arr[i] < _min) _min = mat->__arr[i];
    return _min;
}

inline float findMaximal(const struct matrix *mat) {
    if(!__checkMatrix(mat)) return 0;
    float _max = mat->__arr[0];
    int i, _i = mat->__row * mat->__column;
    for(i = 1; i < _i; ++i) if(mat->__arr[i] > _max) _max = mat->__arr[i];
    return _max;
}

#undef _node
#undef _head

#endif