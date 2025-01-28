// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/?envType=daily-question&envId=2025-01-28
// Maximum Number of Fish in a Grid


// DFS

class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int dfs(vector<vector<int>> &grid, int i, int j, int m, int n) {
        int fish = 0;
        if (grid[i][j] == 0) return fish;
        fish += grid[i][j];
        grid[i][j] = -1;
        for (const auto &dir : directions) {
            int nr = i + dir[0];
            int nc = j + dir[1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                if (grid[nr][nc] > 0) fish += dfs(grid, nr, nc, m, n);
            }
        }
        return fish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxFish = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                maxFish = max(maxFish, dfs(grid, i, j, m, n));
            }
        }
        return maxFish;
    }
};