#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int sumRec(int **matrix, int rows, int cols);
int sumRowRec(int **matrix, int rows, int cols);

int main(void) {
    int x[2][2] = {1,2,3,4};
    // 1 2
    // 3 4

    int baseTest[0][0] = {};
    //
    //
    int lopsided[1][2] = {1,2};
    // 1 2
    int _lopsided[2][1] = {1,2};
    // 1
    // 2
    assert(sumRec(baseTest,0,0) == 0);
    assert(sumRec(x, 2, 2) == 10);
    assert(sumRec(lopsided,1,2) == 3);
    assert(sumRec(_lopsided,2,1) == 3);
    printf("Test cases passed.\n");
}

int sumRec(int **matrix, int rows, int cols) {
    //len = rows * cols - 1
    if(cols <= 0 || rows <= 0) {        // base cases, being safe
        return 0;
    }
    return(sumRec(**matrix, rows - 1, cols) + sumRowRec(**matrix, rows, cols));     //  row + next row
}

int sumRowRec(int **matrix, int rows, int cols) {
    if(cols <= 0 || rows <= 0) {                     // base cases, being safe
        return 0;
    }
    return(sumRowRec(**matrix, rows, cols-1) + matrix[rows-1][cols-1]);           // element + next element
}

// sumRowRec(matrix, rows, cols) = matrix[rows-1][cols-1] + matrix[rows-1][cols-2] .... + matrix[rows-1][0];
// sumRec = sumRowRec(matrix, rows, cols) + sumRowRec(matrix, rows-1, cols) ... + sumRowRec(matrix, 0, cols);

