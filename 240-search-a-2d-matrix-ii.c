/*
   Write an efficient algorithm that searches for a value in an m x n matrix.
   This
   matrix has the following properties:

   Integers in each row are sorted in ascending from left to right.
   Integers in each column are sorted in ascending from top to bottom.
   For example,

   Consider the following matrix:

   [
   [1,   4,  7, 11, 15],
   [2,   5,  8, 12, 19],
   [3,   6,  9, 16, 22],
   [10, 13, 14, 17, 24],
   [18, 21, 23, 26, 30]
   ]
   Given target = 5, return true.

   Given target = 20, return false.
   */

#include <stdbool.h>

bool searchMatrix(int **matrix, int matrixRowSize, int matrixColSize,
                  int target) {
  int row = 0;
  while (matrixColSize > 0) {
    // search the first element greater than or equal to target in the most
    // right column
    for (; row < matrixRowSize; ++row) {
      if (matrix[row][matrixColSize - 1] == target) {
        return true;
      } else if (matrix[row][matrixColSize - 1] > target) {
        break;
      }
    }
    if (row == matrixRowSize) {
      return false; // target is the largest in the current column
    }
    --matrixColSize;
  }

  return false;
}

int main() { return 0; }
