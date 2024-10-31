// Link - https://leetcode.com/problems/minimum-total-distance-traveled/?envType=daily-question&envId=2024-10-31
// Minimum Total Distance Traveled


class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        int m = robot.size(), n = factory.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1));
        
        for (int i = 0; i < m; i++) {
            dp[i][n] = LLONG_MAX;
        }
        
        for (int j = n - 1; j >= 0; j--) {
            long long prefix = 0;
            deque<pair<int, long long>> qq;
            qq.push_back({m, 0});
            
            for (int i = m - 1; i >= 0; i--) {
                prefix += abs(robot[i] - factory[j][0]);
                
                while (!qq.empty() && qq.front().first > i + factory[j][1]) {
                    qq.pop_front();
                }
                
                while (!qq.empty() && qq.back().second >= dp[i][j + 1] - prefix) {
                    qq.pop_back();
                }
                
                qq.push_back({i, dp[i][j + 1] - prefix});
                dp[i][j] = qq.front().second + prefix;
            }
        }
        
        return dp[0][0];
    }
};




// class Solution {
// public:
//     long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
//         int n = robot.size();
//         int m = factory.size();
//         vector<long long> dp(n + 1, 10e12);
//         dp[0] = 0;
//         sort(robot.begin(), robot.end());
//         sort(factory.begin(), factory.end());
//         for (int i = 0; i < m; i++) {
//             int position = factory[i][0];
//             int limit = factory[i][1];
//             while (limit--) {
//                 for (int j = n - 1; j >= 0; j--) {
//                     dp[j + 1] = min(dp[j + 1], abs(robot[j] - position) + dp[j]);
//                 }
//             }
//         }
//         return dp[n];
//     }
// };