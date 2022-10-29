/**
 * @file
 * @brief A library for matrix operations in C.
 * @author DeerInForest[https://github.com/sustechkl]
 * 
 * This is a library for matrix operations in C.
 * I DO NOT claim it to be perfectly safe and efficient, so do not use it in production.
 * However, it is expected to be safe if you always use the functions below instead of
 * access a variable yourself.
*/

#ifndef _MATRIX_LIBRARY
#define _MATRIX_LIBRARY

// Matrix body
struct matrix {
    int __row, __column;
    float *__arr;
};

/**
 * @brief Check is a matrix exists now.
 * @param mat Pointer to the matrix.
 * @return isMatrixExists.
 * @remark Only needed by the author.
*/
inline int __checkMatrix(const struct matrix *mat);

/**
 * @brief Add a matrix.
 * @param mat Pointer to the matrix.
 * @remark Only needed by the author.
*/
inline void __addMatrixNode(struct matrix *mat);

/**
 * @brief Remove a matrix.
 * @param mat Pointer to the matrix.
 * @remark Only needed by the author.
*/
inline void __removeMatrixNode(const struct matrix *mat);

/**
 * @brief Create a new matrix.
 * @param r The number of rows of the matrix.
 * @param c The number of columns of the matrix.
 * @return Null if failed to create, pointer to the new matrix otherwise.
*/
inline struct matrix *createMatrix(int r, int c);

/**
 * @brief Clear a matrix.
 * @param mat Pointer to the matrix.
*/
inline void clearMatrix(struct matrix *const mat);

/**
 * @brief Create a new matrix whose elements are all zero.
 * @param r The number of rows of the matrix.
 * @param c The number of columns of the matrix.
 * @return Null if failed to create, pointer to the new matrix otherwise.
 * @remark Call create and clear.
*/
inline struct matrix *createZeroMatrix(int r, int c);

/**
 * @brief Create a new identical matrix.
 * @param r The number of rows and also columns of the matrix.
 * @return Null if failed to create, pointer to the new matrix otherwise.
*/
inline struct matrix *createIdenticalMatrix(int r);

/**
 * @brief Delete a matrix.
 * @param mat Pointer to the matrix.
 * @return 1 if there's an error, 0 otherwise.
 * @remark Do not free the matrix yourself, because there are some pointers inside.
*/
inline int deleteMatrix(struct matrix *const mat);

/**
 * @brief Delete all matrices.
*/
inline void deleteAllMatrices();

/**
 * @brief Get an element from a matrix.
 * @param mat Pointer to the matrix.
 * @param r Targeted row.
 * @param c Targeted column.
 * @return The element at targeted position, 0 if do not exist.
*/
inline float getMatrixElement(const struct matrix *mat, int r, int c);

/**
 * @brief Get the number of rows of a matrix.
 * @param mat Pointer to the matrix.
 * @return The number of rows of a matrix.
*/
inline int getMatrixRowNumber(const struct matrix *mat);

/**
 * @brief Get the number of columns of a matrix.
 * @param mat Pointer to the matrix.
 * @return The number of columns of a matrix.
*/
inline int getMatrixColumnNumber(const struct matrix *mat);

/**
 * @brief Set an element in a matrix.
 * @param mat Pointer to the matrix.
 * @param r Targeted row.
 * @param c Targeted column.
 * @return 1 if there's an error, 0 otherwise.
*/
inline int setMatrixElement(struct matrix *const mat, int r, int c, float val);

/**
 * @brief Copy all the data from the original matrix to the targeted matrix.
 * @param targetedMat Pointer to the targeted matrix.
 * @param originalMat Pointer to the original matrix.
 * @return 1 if there's an error, 0 otherwise.
 * @remark All data in the targeted matrix will be eliminated.
*/
inline int copyMatrix(struct matrix *const targetedMat, const struct matrix *originalMat);

/**
 * @brief Create a new matrix, who is a copy of an exists matrix.
 * @param mat Pointer to the matrix.
 * @return NULL if failed to create, pointer to the new matrix otherwise.
*/
inline struct matrix *createMatrixCopy(const struct matrix *mat);

/**
 * @brief Add a scalar to all elements in a matrix.
 * @param mat Pointer to the matrix.
 * @param val The scalar.
 * @return 1 if there's an error, 0 otherwise.
*/
inline int addScalar(struct matrix *const mat, float val);

/**
 * @brief Subtract a scalar from all elements in a matrix.
 * @param mat Pointer to the matrix.
 * @param val The scalar.
 * @return 1 if there's an error, 0 otherwise.
*/
inline int subtractScalar(struct matrix *const mat1, float val);

/**
 * @brief Multiply all elements in a matrix with a scalar.
 * @param mat Pointer to the matrix.
 * @param val The scalar.
 * @return 1 if there's an error, 0 otherwise.
*/
inline int multiplyScalar(struct matrix *const mat, float val);

/**
 * @brief Add two matrices, do mat1 = mat1 + mat2.
 * @param mat1 Pointer to one matrix.
 * @param mat2 Pointer to another.
 * @return 1 if there's an error, 0 otherwise.
 * @remark If r or c of mat1 and mat2 are different, nothing will happened.
*/
inline int addMatrix(struct matrix *const mat1, const struct matrix *mat2);

/**
 * @brief Subtract two matrices, do mat1 = mat1 - mat2.
 * @param mat1 Pointer to one matrix.
 * @param mat2 Pointer to another.
 * @return 1 if there's an error, 0 otherwise.
 * @remark If r or c of mat1 and mat2 are different, nothing will happened.
*/
inline int subtractMatrix(struct matrix *const mat1, const struct matrix *mat2);

/**
 * @brief Multiply two matrices, do mat1 = mat1 * mat2.
 * @param mat1 Pointer to one matrix.
 * @param mat2 Pointer to another.
 * @return 1 if there's an error, 0 otherwise.
 * @remark If c of mat1 and r of mat2 are different, nothing will happened.
*/
inline int multiplyMatrix(struct matrix *const mat1, const struct matrix *mat2);

/**
 * @brief Find the minimal element in a matrix.
 * @param mat Pointer to the matrix.
 * @return The minimal value.
*/
inline float findMinimal(const struct matrix *mat);

/**
 * @brief Find the maximal element in a matrix.
 * @param mat Pointer to the matrix.
 * @return The maximal value.
*/
inline float findMaximal(const struct matrix *mat);


#endif /*_MATRIX_LIBRARY*/