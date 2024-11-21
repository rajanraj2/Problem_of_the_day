// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/?envType=daily-question&envId=2024-11-21
// count unguarded cells in the grid


class Solution {
private:
    void helper(vector<vector<int>>& vis, int& m, int& n, int x, int y, int dx, int dy) {
        while (x >= 0 && x < m && y >= 0 && y < n) {
            if (vis[x][y] == 2 || vis[x][y] == 3) break;
            if (vis[x][y] == 0) vis[x][y] = 1;
            x += dx;
            y += dy;
        }
    }

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> vis(m, vector<int> (n, 0));
        for (const auto& it : guards) vis[it[0]][it[1]] = 3;
        for (const auto& it : walls) vis[it[0]][it[1]] = 2;

        vector<int> arr1 = {0, 1, 0, -1};
        vector<int> arr2 = {1, 0, -1, 0};

        for (const auto& it : guards) {
            int x = it[0], y = it[1];
            for (int i = 0; i < 4; i++) {
                int a = arr1[i], b = arr2[i];
                helper(vis, m, n, x + a, y + b, a, b);
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0) count++;
            }
        }
        return count;
    }
};