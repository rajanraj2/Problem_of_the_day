// https://leetcode.com/problems/count-servers-that-communicate/?envType=daily-question&envId=2025-01-23
// 1267. Count Servers that Communicate


class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int result = 0;
        vector<int> row(n, 0), col(m, 0);
        
        for (int i = 0; i < n; i++) {
            int r = 0;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) r++;
                if (r >= 2) {
                    row[i] = 1;
                    break;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            int c = 0;
            for (int j = 0; j < n; j++) {
                if (grid[j][i] == 1) c++;
                if (c >= 2) {
                    col[i] = 1;
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) continue;
                if (row[i] || col[j]) result++;
            }
        }
        return result;
    }
};