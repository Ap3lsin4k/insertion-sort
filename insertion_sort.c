#include "insertion_sort.h"



void insertion_sort_next(int **matrix, unsigned short totalRows, unsigned short focusColumn, unsigned short firstUnsorted) {
    if (firstUnsorted == 0 || firstUnsorted >= totalRows)
        return;

    __insertion_sort_next(matrix, focusColumn, firstUnsorted);
}

void insertion_sort_all_columns(int **matrix, unsigned short totalRows, unsigned short totalColumns)
{
    for (int col=0; col<totalColumns; ++col)
        insertion_sort_one_column(matrix, totalRows, col);
}

void insertion_sort_one_column(int **matrix, unsigned short totalRows, unsigned short focusColumn)
{
    for (unsigned short numberOfSorted = 1; numberOfSorted < totalRows; ++numberOfSorted)
        __insertion_sort_next(matrix, focusColumn, numberOfSorted);
}


void __insertion_sort_next(int *const *matrix, unsigned short focusColumn, unsigned short firstUnsorted) {
    for (unsigned short j=0; j < firstUnsorted; ++j)
        if ( matrix[firstUnsorted][focusColumn] < matrix[j][focusColumn])
        {
            int t = matrix[firstUnsorted][focusColumn];
            for (unsigned int k=firstUnsorted; k>j; k--)
                matrix[k][focusColumn] = matrix[k-1][focusColumn];

            matrix[j][focusColumn]= t;
        }
}


