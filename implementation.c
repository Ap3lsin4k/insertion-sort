#include <stdbool.h>
#include "implementation.h"

//
// Created by Andy on 2020-11-29.
//

bool is_wanted(double thief)
{
    return 0 <= thief && thief <= 5;
}

bool less_than_wanted(double thief)
{
    return thief < 0;
}

bool greater_than_wanted(double thief)
{
    return thief > 5;
}

void imprison(struct position* pos, unsigned short row, unsigned short col)
{
    pos->found = true;
    pos->row = row;
    pos->column = col;
}

void binarySearchInLastRow(double *const *city, unsigned short columns, struct position *pos, unsigned short last_row_index);
void binarySearchInFirstColumn(double *const *city, struct position *pos, unsigned short last_row);

void sort(int **matrix)
{

}