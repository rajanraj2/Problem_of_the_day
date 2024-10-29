// Link - https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/?envType=daily-question&envId=2024-10-29
// Maximum Number of Moves in a Grid


class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int result = 0;
        vector<int> dp(m);

        for (int j = 1; j < n; j++) {
            int leftTop = 0;
            bool found = false;

            for (int i = 0; i < m; i++) {
                int cur = -1;
                int nextLeftTop = dp[i];

                if (i - 1 >= 0 && leftTop != -1 && grid[i][j] > grid[i - 1][j - 1]) {
                    cur = max(cur, leftTop + 1);
                }

                if (dp[i] != -1 && grid[i][j] > grid[i][j - 1]) {
                    cur = max(cur, dp[i] + 1);
                }

                if (i + 1 < m && dp[i + 1] != -1 && grid[i][j] > grid[i + 1][j - 1]) {
                    cur = max(cur, dp[i + 1] + 1);
                }

                dp[i] = cur;
                found = found || (dp[i] != -1);
                leftTop = nextLeftTop;
            }

            if (!found) break;
            result = j;
        }

        return result;
    }
};