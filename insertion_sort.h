//
// Created by Andrew on 2020-11-29.
//
#include <stdbool.h>
#include <stdlib.h>

#ifndef L2_1_THIRD_IMPLEMENTATION_H
#define L2_1_THIRD_IMPLEMENTATION_H

void insertion_sort_all_columns(int **matrix, unsigned short totalRows, unsigned short totalColumns);
void insertion_sort_one_column(int **matrix, unsigned short totalRows, unsigned short focusColumn);
void insertion_sort_next(int **matrix, unsigned short totalRows, unsigned short focusColumn, unsigned short firstUnsorted);

void __insertion_sort_next(int *const *matrix, unsigned short focusColumn, unsigned short firstUnsorted);


#define INITIALIZE_MATRIX(matrix, in_const_matrix) \
    const unsigned short rows = sizeof(input)/sizeof(input[0]); \
    const unsigned short columns = sizeof(input[0])/sizeof(input[0][0]); \
    ALLOCATE_MATRIX(matrix, rows, columns)                        \
    FILL_MATRIX_FROM_CONSTANT_MATRIX(matrix, in_const_matrix, rows, columns)


#define ALLOCATE_MATRIX(matrix, rows, columns) \
    int **matrix; \
    matrix = malloc(rows * sizeof *matrix);            \
    for (unsigned short i=0; i<rows; i++)                 \
        matrix[i] = malloc(columns * sizeof *matrix[i]);


#define FREE_MATRIX(matrix) \
    for (unsigned short i=0; i<rows; i++)              \
        free(matrix[i]);                     \
    free(matrix);


#define FILL_MATRIX_FROM_CONSTANT_MATRIX(out_matrix, const_matrix, rows, columns) \
    for (unsigned short i=0; i < rows; ++i) \
        for (unsigned short j=0; j<columns; ++j)\
            out_matrix[i][j] = const_matrix[i][j];





#endif //L2_1_THIRD_IMPLEMENTATION_H
