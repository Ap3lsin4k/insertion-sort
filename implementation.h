//
// Created by Andrew on 2020-11-29.
//
#include <stdbool.h>
#include <stdlib.h>

#ifndef L2_1_THIRD_IMPLEMENTATION_H
#define L2_1_THIRD_IMPLEMENTATION_H

void sort(int **matrix);




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


#define FILL_MATRIX(out_array, const_expression, rows, columns) \
    double const_array[rows][columns] = const_expression;            \
    for (unsigned short i=0; i < rows; ++i)   \
        for (unsigned short j=0; j<columns; ++j)   \
            out_array[i][j] = const_array[i][j];

#define FREE_MATRIX(matrix) \
    for (unsigned short i=0; i<rows; i++)              \
        free(matrix[i]);                     \
    free(matrix);

#define CALL_FUNCTION_WITH_MATRIX(my_function, matrix_brackets, rows, columns) \
    ALLOCATE_MATRIX(matrix, rows, columns);              \
    FILL_ARRAY(matrix, matrix_brackets, rows, columns);   \
                                                 \
    struct position result = find_thieves(city, rows, columns);          \
    DEALLOCATE_MATRIX(matrix, rows, columns);                      \


#define FILL_MATRIX_FROM_CONSTANT_MATRIX(out_matrix, const_matrix, rows, columns) \
    for (unsigned short i=0; i < rows; ++i) \
        for (unsigned short j=0; j<columns; ++j)\
            out_matrix[i][j] = const_matrix[i][j];

#define FIND_THIEVES_IN_CITY(my_city, rows, columns) \
    ALLOCATE_MATRIX(dynamic_matrix_city, rows, columns);              \
    FILL_MATRIX_FROM_CONSTANT_MATRIX(dynamic_matrix_city, my_city, rows, columns);   \
    struct position result = find_thieves(dynamic_matrix_city, rows, columns);          \
    DEALLOCATE_MATRIX(dynamic_matrix_city, rows, columns);

struct position
{
    bool found;
    unsigned short row, column;
};

struct position find_thieves(double **city, unsigned short rows, unsigned short cols);






#endif //L2_1_THIRD_IMPLEMENTATION_H
