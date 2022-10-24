/**
 * @file
 * @brief A library for matrix operations in C.
 * @author DeerInForest[https://github.com/sustechkl]
 * 
 *  This is a library for matrix operations in C.
 *  I don't claim it to be perfectly safe and efficient, so do not use it in production.
*/

#ifndef _MATRIX_LIBRARY
#define _MATRIX_LIBRARY

// Matrix body
struct matrix {
    int row, column;
    float *arr;
};


/**
 * @brief Create a new matrix.
 * @param r The number of rows of the matrix.
 * @param c The number of columns of the matrix.
 * @return Null if failed to create, pointer to the new matrix.
*/
inline struct matrix *createMatrix(int r, int c);

/**
 * @brief Create a new matrix whose elements are all zero.
 * @param r The number of rows of the matrix.
 * @param c The number of columns of the matrix.
 * @return Null if failed to create, pointer to the new matrix.
 * @remark Call create and clear.
*/
inline struct matrix *createZeroMatrix(int r, int c);

/**
 * @brief Create a new identical matrix.
 * @param r The number of rows and also columns of the matrix.
 * @return Null if failed to create, pointer to the new matrix.
*/
inline struct matrix *createIdenticalMatrix(int r);

/**
 * @brief Delete a matrix.
 * @param mat Pointer to the matrix.
 * @return 1 if there's an error, 0 otherwise.
 * @remark Do not free the matrix yourself, because there are some pointers inside.
*/
inline int deleteMatrix(struct matrix *mat);

/**
 * @brief Get an element from a matrix.
 * @param mat The targeted matrix.
 * @param r Targeted row.
 * @param c Targeted column.
 * @return The element at targeted position, 0 if do not exist.
*/
inline float getMatrixElement(const struct matrix * mat, int r, int c);

/**
 * @brief Set an element in a matrix.
 * @param mat The targeted matrix.
 * @param r Targeted row.
 * @param c Targeted column.
 * @return 1 if there's an error, 0 otherwise.
*/
inline int setMatrixElement(struct matrix * mat, int r, int c, float val);

/**
 * @brief Copy all the data from the original matrix to the targeted matrix.
 * @param targetedMat Pointer to the targeted matrix.
 * @param originalMat Pointer to the original matrix.
 * @remark All data in targeted matrix will be eliminated.
*/
inline void copyMatrix(struct matrix *targetedMat, const struct matrix *originalMat);

/**
 * @brief Add two matrices.
 * @param mat1 Pointer to one matrix.
 * @param mat2 Pointer to the other one.
 * @return NULL if r or c of mat1 and mat2 are different, the pointer to the result otherwise.
*/
inline struct matrix *addMatrix(const struct matrix *mat1, const struct matrix *mat2);

/**
 * @brief Subtract two matrices.
 * @param mat1 Pointer to one matrix.
 * @param mat2 Pointer to another.
 * @return NULL if r or c of mat1 and mat2 are different, the pointer to the result otherwise.
*/
inline struct matrix *subtractMatrix(const struct matrix *mat1, const struct matrix *mat2);

/**
 * @brief Add a scalar to all elements in mat1.
 * @param mat1 Targeted matrix.
 * @param val The scalar.
*/
inline void addScalar(struct matrix *mat1, float val);

/**
 * @brief Subtract a scalar from all elements in mat1.
 * @param mat1 Targeted matrix.
 * @param val The scalar.
*/
inline void subtractScalar(struct matrix *mat1, float val);

/**
 * @brief Multiply all elements in mat1 with a scalar.
 * @param mat1 Targeted matrix.
 * @param val The scalar.
*/
inline void multiplyScalar(struct matrix *mat1, float val);

/**
 * @brief Multiply two matrices.
 * @param mat1 Pointer to one matrix.
 * @param mat2 Pointer to another.
 * @return NULL if mat1->c != mat2->r, pointer to the result otherwise.
*/
inline struct matrix *multiplyMatrix(const struct matrix *mat1, const struct matrix *mat2);

/**
 * @brief Find the minimal element in a matrix.
 * @param mat Pointer to the targeted matrix.
 * @return The minimal value.
*/
inline float findMinimal(const struct matrix *mat);

/**
 * @brief Find the maximal element in a matrix.
 * @param mat Pointer to the targeted matrix.
 * @return The maximal value.
*/
inline float findMaximal(const struct matrix *mat);

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


#endif /*_MATRIX_LIBRARY*/