//
// Created by Andrew on 2020-11-01.
//

#ifndef L2_1_UNITTEST_H
#define L2_1_UNITTEST_H


#include <stdio.h>

#define assert_true(condition) \
{                                       \
    if(condition)              \
        printf("Success. The statement is true.");\
    else                  \
        printf("Failed. The statement is false.\n");\
    \
}

#define assert_true_w_msg(message, condition) \
{                                       \
    if(condition)              \
        printf("Success. %s\n", message);\
    else                  \
        printf("Failed. %s is false.\n", message);\
    \
}

#define assert_equal_double(result, expected) \
{                                       \
    if(result == expected)              \
        printf("Success. Result: %lf\n", result);\
    else                  \
        printf("Failed. %lf != %lf\n", result, expected);\
    \
}

#define assert_equal(result, expected) \
{                                       \
    if(result == expected)              \
        printf("Success. Result is as expected: %d\n", result);\
    else                  \
        printf("Failed. %d != %d\n", result, expected);\
    \
}


void assert_equal_w_msg(char message[], int result, int expected)
{
    if(result == expected)              \
        printf("Success. %s: %d\n", message, result);\
    else                  \
        printf("Failed. %d != %d\n", result, expected);
}

#define ___assert_matrices_are_equal(when, result_matrix, const_expression) \
    const unsigned short number_of_rows = sizeof(result_matrix) / sizeof(result_matrix[0]), \
    number_of_columns = sizeof(result_matrix[0]) / sizeof(result_matrix[0][0]);                  \
    int const_matrix[number_of_rows][1] = const_expression;                                  \
    assert_matrices_are_equal(when, result_matrix, const_matrix)\


#define assert_matrices_are_equal(when, result_matrix, expected_matrix) {              \
    const unsigned short my_rows = sizeof(expected_matrix) / sizeof(expected_matrix[0]), \
    my_columns = sizeof(expected_matrix[0]) / sizeof(expected_matrix[0][0]);               \
    bool error=false;                                                              \
    for (unsigned short i=0; i < my_rows; ++i)   \
    {\
    for (unsigned short j=0; j < my_columns; ++j){\
    if (result_matrix[i][j] != expected_matrix[i][j] )        \
            {                                                     \
            printf("\nFailed to insertion_sort_one_column when %s. Matrices with size[%u][%u], are not equal at i=%u, j=%u. Expected to be equal %d but got %d", \
                when, my_rows, my_columns, i, j, expected_matrix[i][j], result_matrix[i][j]);\
            error = true;                                     \
            }                                                     \
        }\
} if (!error)                                                \
        printf("Successfully sorted matrix with size[%u][%u] when %s.\n", my_rows, my_columns, when);                                       \
        else                                                                           \
            printf("\n\n");                                       \
        \
}

#define assert_equal_llu(result, expected) \
{                                       \
    if (result == expected)              \
        printf("Success. Result: %llu\n", result);\
    else                  \
        printf("Failed. %llu != %llu\n", result, expected);\
    \
}

#endif //L2_1_UNITTEST_H
