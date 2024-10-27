// Link - https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/?envType=daily-question&envId=2024-10-27
// Count Square Submatrices with All Ones


class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        int result = 0;

        for (int i = 0; i < n; i++) {
            dp[i][0] = matrix[i][0];
            result += dp[i][0];
        }

        for (int i = 1; i < m; i++) {
            dp[0][i] = matrix[0][i];
            result += dp[0][i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 1) {
                    dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
                }
                result += dp[i][j];
            }
        }
        
        return result;
    }
};