// Link - https://leetcode.com/problems/magic-squares-in-grid/description/?envType=daily-question&envId=2024-08-09
// Magic Squares in Grid


class Solution {
private:
    bool isMagicSquare(vector<vector<int>>& grid, int x, int y) {
        // Check if the subgrid contains distinct numbers from 1 to 9
        vector<int> count(16, 0);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int num = grid[x + i][y + j];
                if (num < 1 || num > 9) return false;
                count[num]++;
                if (count[num] > 1) return false;
            }
        }

        // Check the sums of rows, columns, and diagonals
        int sum = grid[x][y] + grid[x][y + 1] + grid[x][y + 2];
        
        // Rows
        if (grid[x + 1][y] + grid[x + 1][y + 1] + grid[x + 1][y + 2] != sum) return false;
        if (grid[x + 2][y] + grid[x + 2][y + 1] + grid[x + 2][y + 2] != sum) return false;

        // Columns
        if (grid[x][y] + grid[x + 1][y] + grid[x + 2][y] != sum) return false;
        if (grid[x][y + 1] + grid[x + 1][y + 1] + grid[x + 2][y + 1] != sum) return false;
        if (grid[x][y + 2] + grid[x + 1][y + 2] + grid[x + 2][y + 2] != sum) return false;

        // Diagonals
        if (grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2] != sum) return false;
        if (grid[x][y + 2] + grid[x + 1][y + 1] + grid[x + 2][y] != sum) return false;

        return true;
    }
    
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for (int i = 0; i <= rows - 3; ++i) {
            for (int j = 0; j <= cols - 3; ++j) {
                if (isMagicSquare(grid, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
};