// Link - https://leetcode.com/problems/stone-game-ii/description/?envType=daily-question&envId=2024-08-20
// Stone Game II


class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        vector<int> suffixSum(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int M = 1; M <= n; M++) {
                int maxi = 0;
                for (int X = 1; X <= 2 * M && i + X <= n; X++) {
                    maxi = max(maxi, suffixSum[i] - dp[i + X][max(M, X)]);
                }
                dp[i][M] = maxi;
            }
        }

        return dp[0][1];
    }
};