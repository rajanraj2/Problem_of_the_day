// https://leetcode.com/problems/minimum-cost-for-tickets/description/?envType=daily-question&envId=2024-12-31
// Minimum Cost For Tickets


class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int m = days.back(), d0 = days[0];
        vector<int> dp(m + 1, 0);

        for (int d = d0, i = 0; d <= m; d++) {
            if (d == days[i]) {
                i++;
                dp[d] = min({costs[0] + dp[max(d - 1, 0)], costs[1] + dp[max(d - 7, 0)], 
                costs[2] + dp[max(d - 30, 0)]});
            }
            else dp[d] = dp[d - 1];
        }
        return dp[m];
    }
};