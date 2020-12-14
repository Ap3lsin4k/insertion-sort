#include "unittest.h"
#include "stdio.h"
#include "../insertion_sort.h"
#include <stdlib.h>

#define TEST_INSERTION_SORT_NEXT(when, input, expected, number_of_sorted) \
    INITIALIZE_MATRIX(matrix, input)                     \
    const unsigned short number_of_rows = sizeof(input)/sizeof(input[0]); \
    insertion_sort_next(matrix, number_of_rows, 0, number_of_sorted); \
    assert_matrices_are_equal(when, matrix, expected) \
    FREE_MATRIX(matrix)

#define TEST_INSERTION_SORT_EACH_NEXT(number_of_sorted) \
    insertion_sort_next(matrix, number_of_rows, 0, number_of_sorted);\
    assert_matrices_are_equal("", matrix, expected);

#define TEST_INSERTION_SORT_FOR_FOCUS_COLUMN(number_of_sorted) \
    insertion_sort_next(matrix, number_of_rows, focus_column, number_of_sorted);\
    assert_matrices_are_equal("should sort second column", matrix, expected);

void test_when_two_rows();

void test_control_cases();

int main(void) {
    {
        int input[4][3] = {{1,1,1},{2,2,2},{3,3,3}, {3,5,4}};
        INITIALIZE_MATRIX(matrix, input)


        const unsigned short number_of_rows = sizeof(input)/sizeof(input[0]), number_of_columns = sizeof(input[0])/sizeof(input[0][0]);
        assert_equal(number_of_rows, 4)
        assert_equal(number_of_columns, 3)
    }
    {
        int input[4][5] = {{1,1,1,5,6},{2,2,2,3,4},{3,3,3,4,5}, {3,5,4,6,7}};

        const unsigned short number_of_rows = sizeof(input)/sizeof(input[0]), columns = sizeof(input[0])/sizeof(input[0][0]);
        assert_equal(number_of_rows, 4)
        assert_equal_w_msg("Should find number of columns in matrix in real time", columns, 5);
    }

    {
        int input[2][5] = {{1,1,1,5,6},{2,2,2,3,4}};

        const unsigned short number_of_rows = sizeof(input)/sizeof(input[0]), number_of_columns = sizeof(input[0])/sizeof(input[0][0]);
        assert_equal(number_of_rows, 2)
        assert_equal(number_of_columns, 5)
    }
    {
        int input[1][1] = {{10}};
        INITIALIZE_MATRIX(matrix, input)
        insertion_sort_one_column(matrix, 1, 0);
        assert_equal(matrix[0][0], input[0][0])
        FREE_MATRIX(matrix)
    }
    {
        int input[3][1] = {{3}, {20}, {30}};
        INITIALIZE_MATRIX(matrix, input)
        insertion_sort_one_column(matrix, 3, 0);
        assert_matrices_are_equal("initial matrix is already ordered", matrix, input)
        FREE_MATRIX(matrix)
    }
    {
        int input[3][1] = {{-2}, {-1}, {0}};
        INITIALIZE_MATRIX(matrix, input)
        insertion_sort_one_column(matrix, 3, 0);
        assert_matrices_are_equal("initial matrix is already ordered and with negative numbers", matrix, input)
        insertion_sort_next(matrix, 3, 0, 2);
        assert_matrices_are_equal("pivot is equal to total number of rows", matrix, input)
        insertion_sort_next(matrix, 3, 0, 3);
        assert_matrices_are_equal("pivot is equal to total number of rows", matrix, input)
        FREE_MATRIX(matrix)
    }
    {
        int input[2][1] = {{9}, {1}};
        int expected[2][1] = {{1}, {9}};
        INITIALIZE_MATRIX(matrix, input)
        insertion_sort_next(matrix, 2, 0, 0);
        assert_matrices_are_equal("number of sorted elements (aka pivot) was 0", matrix, input)
        insertion_sort_next(matrix, 2, 0, 1);
        assert_matrices_are_equal("number of sorted elements (aka pivot) was 1", matrix, expected)
        insertion_sort_next(matrix, 2, 0, 2);
        assert_matrices_are_equal("number of sorted elements (aka pivot) equal to number of rows", matrix, expected)

        FREE_MATRIX(matrix)
    }
    {
        int input[][1] = {{3}, {0}, {-2}};
        INITIALIZE_MATRIX(matrix, input)
        insertion_sort_next(matrix, 3, 0, 0);
        assert_matrices_are_equal("number of sorted elements (aka pivot) was 0", matrix, input)
        insertion_sort_next(matrix, 3, 0, 1);

        {
            int expected[3][1] = {{0}, {3}, {-2}};
            assert_matrices_are_equal("number of sorted elements (aka pivot) was 1", matrix, expected)
        }
        insertion_sort_next(matrix, 3, 0, 2);
        int expected[][1] = {{-2}, {0}, {3}};
        assert_matrices_are_equal("number of sorted elements (aka pivot) equal to number of rows", matrix, expected)

        FREE_MATRIX(matrix)
    }
    {
        int input[][1] = {{1}, {2}, {4}, {-5}};
        int expected[][1] = {{-5}, {1}, {2}, {4}};
        TEST_INSERTION_SORT_NEXT("last element should be put at the beginning", input, expected, 3)
    }
    {
        int input[][1] = {{6}, {8}, {7}};
        int expected[][1] = {{6}, {7}, {8}};
        TEST_INSERTION_SORT_NEXT("last element must be put into middle", input, expected, 2)
    }
    {
        int input[][1] = {{5}, {10}, {20}, {15}};
        int expected[][1] = {{5}, {10}, {15}, {20}};
        TEST_INSERTION_SORT_NEXT("last element must be put into middle", input, expected, 3)
    }
    {
        int input[][1] = {{24}, {-8}, {4}, {2}};
        INITIALIZE_MATRIX(matrix, input)                     \
        const unsigned short number_of_rows = sizeof(input)/sizeof(input[0]);
        {
            int expected[][1] = {{-8}, {24}, {4}, {2}};
            insertion_sort_next(matrix, number_of_rows, 0, 1);
            assert_matrices_are_equal("number of sorted was: 1", matrix, expected)
        }
        {
            int expected[][1] = {{-8}, {4}, {24}, {2}};
            insertion_sort_next(matrix, number_of_rows, 0, 2);
            assert_matrices_are_equal("number of sorted was: 2", matrix, expected);
        }
        {
            insertion_sort_next(matrix, number_of_rows, 0, 3);
            int expected[][1] = {{-8}, {2}, {4}, {24}};
            assert_matrices_are_equal("number of sorted was: 3", matrix, expected);
        }
        FREE_MATRIX(matrix)
    }
    {
            int input[][1] = {{-9}, {18}, {3}, {-6}, {-6}, {6}, {12}, {21}, {-10}, {3}, {9}};
            INITIALIZE_MATRIX(matrix, input)
            const unsigned short number_of_rows = sizeof(input)/sizeof(input[0]);
        {
            int expected[][1] = {{-9}, {18}, {3}, {-6}, {-6}, {6}, {12}, {21}, {-10}, {3}, {9}};
            TEST_INSERTION_SORT_EACH_NEXT(1)
        }
        {
            int expected[][1] = {{-9}, {3}, {18}, {-6}, {-6}, {6}, {12}, {21}, {-10}, {3}, {9}};
            TEST_INSERTION_SORT_EACH_NEXT(2)
        }
        {
            int expected[][1] = {{-9}, {-6}, {3}, {18}, {-6}, {6}, {12}, {21}, {-10}, {3}, {9}};
            TEST_INSERTION_SORT_EACH_NEXT(3)
        }
        {
            int expected[][1] = {{-9}, {-6}, {-6}, {3}, {18}, {6}, {12}, {21}, {-10}, {3}, {9}};
            TEST_INSERTION_SORT_EACH_NEXT(4)
        }
        {
            int expected[][1] = {{-9}, {-6}, {-6}, {3}, {6}, {18}, {12}, {21}, {-10}, {3}, {9}};
            TEST_INSERTION_SORT_EACH_NEXT(5)
        }
        {
            int expected[][1] = {{-9}, {-6}, {-6}, {3}, {6}, {12}, {18}, {21}, {-10}, {3}, {9}};
            TEST_INSERTION_SORT_EACH_NEXT(6)
        }
        {
            int expected[][1] = {{-9}, {-6}, {-6}, {3}, {6}, {12}, {18}, {21}, {-10}, {3}, {9}};
            TEST_INSERTION_SORT_EACH_NEXT(7)
        }
        {
            int expected[][1] = {{-10}, {-9}, {-6}, {-6}, {3}, {6}, {12}, {18}, {21}, {3}, {9}};
            TEST_INSERTION_SORT_EACH_NEXT(8)
        }
        {
            int expected[][1] = {{-10}, {-9}, {-6}, {-6}, {3}, {3}, {6}, {12}, {18}, {21}, {9}};
            TEST_INSERTION_SORT_EACH_NEXT(9)
        }
        {
            int expected[][1] = {{-10}, {-9}, {-6}, {-6}, {3}, {3}, {6}, {9}, {12}, {18}, {21}};
            TEST_INSERTION_SORT_EACH_NEXT(10)
        }
        FREE_MATRIX(matrix)
    }
    test_when_two_rows();
    test_control_cases();

    printf("\n");

    return 0;
}

void test_control_cases() {
    int input[][3] = {{1, 7, 6},
                      {2, 4, 5},
                      {3, 5, 4},
                      {7, 1, 3},};

    int expected[][3] = {{1, 1, 3},
                      {2, 4, 4},
                      {3, 5, 5},
                      {7, 7, 6}};

    INITIALIZE_MATRIX(matrix, input)
    insertion_sort_all_columns(matrix, 4, 3);
    assert_matrices_are_equal("sorted, shuffled, reversed sorted", matrix, expected);
    FREE_MATRIX(matrix)
}

void test_when_two_rows() {
    unsigned int focus_column = 1;
    int input[][2] = {{1, 7},
                      {2, 4},
                      {3, 5},
                      {4, 2},
                      {5, 3},};

    INITIALIZE_MATRIX(matrix, input)
    const unsigned short number_of_rows = sizeof(input)/sizeof(input[0]);

    {
        int expected[][2] = {{1, 4},
                          {2, 7},
                          {3, 5},
                          {4, 2},
                          {5,3}};
        TEST_INSERTION_SORT_FOR_FOCUS_COLUMN(1);
    }

    {
        int expected[][2] = {{1, 4},
                             {2, 5},
                             {3, 7},
                             {4, 2},
                             {5,3}};
        TEST_INSERTION_SORT_FOR_FOCUS_COLUMN(2);
    }
    {
        int expected[][2] = {
                {1, 2},
                {2, 4},
                {3, 5},
                {4, 7},
                {5, 3}};
        TEST_INSERTION_SORT_FOR_FOCUS_COLUMN(3);
    }
    {
        int expected[][2] = {
                {1, 2},
                {2, 3},
                {3, 4},
                {4, 5},
                {5, 7}};
        TEST_INSERTION_SORT_FOR_FOCUS_COLUMN(4);
    }
    FREE_MATRIX(matrix)
}



