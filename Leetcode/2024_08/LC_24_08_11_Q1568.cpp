// Link - https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/description/?envType=daily-question&envId=2024-08-11
// Minimum Number of Days to Disconnect Island


class Solution {
private:
    int countIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int islands = 0;

        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};

        function<void(int, int)> dfs = [&](int row, int col) {
            vis[row][col] = 1;
            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                    dfs(nrow, ncol);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    islands++;
                    if (islands > 1) return islands;
                    dfs(i, j);
                }
            }
        }

        return islands;
    }
    
public:
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (countIslands(grid) != 1) return 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (countIslands(grid) != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};