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

#define assert_matrices_are_equal(when, result_matrix, expected_matrix) \
        {                                                                 \
    const unsigned short my_rows = sizeof(input) / sizeof(input[0]), \
    my_columns = sizeof(input[0]) / sizeof(input[0][0]);               \
    bool error=false;                                                              \
    for (unsigned short i=0; i < my_rows; ++i)   \
    {\
for (unsigned short j=0; j < my_columns; ++j){\
if (matrix[i][j] != input[i][j] )        \
            {                                                     \
            printf("Failed to sort when %s. Matrices with size[%u][%u], are not equal at i=%u, j=%u. Expected to be equal %d but got %d\n", \
                when, my_rows, my_columns, i, j, matrix[i][j], input[i][j]);\
            error = true;                                     \
            }                                                     \
        }\
} if (!error)                                                \
        printf("Successfully sorted matrix with size[%u][%u] when %s.\n", my_rows, my_columns, when);\
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
