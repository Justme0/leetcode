#include <iostream>
#include <vector>



class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
            int num = 0;

            if (grid.empty()) {
                    return 0;
            }

            if (grid.front().empty()) {
                    return 0;
            }

            M = grid.size();
            N = grid.front().size();

            for (int i = 0; i < M; ++i) {
                    for (int j = 0; j < N; ++j) {
                            if (grid[i][j] == kIsland) {
                                    ++num;
                                    visit(grid, i, j);
                            }
                    }
            }

            return num;
    }

private:

    // make [i, j] surrounding area visited
    void visit(std::vector<std::vector<char>>& grid, int i, int j) {
            grid[i][j] = kVisited;

            if (i - 1 >= 0 && kIsland == grid[i - 1][j]) {
                    visit(grid, i - 1, j);
            }

            if (j - 1 >= 0 && kIsland == grid[i][j - 1]) {
                    visit(grid, i, j - 1);
            }

            if (i + 1 < M && kIsland == grid[i + 1][j]) {
                    visit(grid, i + 1, j);
            }

            if (j + 1 < N && kIsland == grid[i][j + 1]) {
                    visit(grid, i, j + 1);
            }
    }

private:

    const char kWater = '0';
    const char kIsland = '1';
    const char kVisited = '2';

    int M = 0;
    int N = 0;
};

int main()
{


}
