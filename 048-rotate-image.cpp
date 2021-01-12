// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

// NOTE: n-i-1, size-index-1 should minus one!!!

#include <iostream>
#include <vector>

class Solution {
public:
    void moveFourPoints(std::vector<std::vector<int>>& m, int i, int j) {
        int n = m.size();
        int tmp = m[i][j];
        m[i][j] = m[n-j-1][i];
        m[n-j-1][i] = m[n-i-1][n-j-1];
        m[n-i-1][n-j-1] = m[j][n-i-1];
        m[j][n-i-1] = tmp;
    }

    // move a single row
    // start from (index, index)
    void moveCircle(std::vector<std::vector<int>>& matrix, int index) {
        for (int j = index; j < static_cast<int>(matrix.size()) - index - 1; ++j) {
            moveFourPoints(matrix, index, j);
        }
    }

    void rotate(std::vector<std::vector<int>>& matrix) {
        for (int i = 0; i < matrix.size() / 2; ++i) {
            moveCircle(matrix, i);
        }
    }
};
