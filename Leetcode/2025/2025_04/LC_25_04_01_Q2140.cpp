// https://leetcode.com/problems/solving-questions-with-brainpower/?envType=daily-question&envId=2025-04-01
// 2140. Solving Questions With Brainpower


class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            int n = questions.size();
            vector<long long> dp(n, 0);
            dp[n - 1] = questions[n - 1][0];
            int next = n;
    
            for (int i = n - 2; i >= 0; i--) {
                next = i + 1 + questions[i][1];
                dp[i] = questions[i][0]; 
                if (next < n) dp[i] += dp[next];
                dp[i] = max(dp[i], dp[i + 1]);
            }
    
            return dp[0];
        }
    };
    
    
    // write recursive solution exploring all possibilities
    
    // recusive solution with memo
    
    // class Solution {
    // private:
    //     long long helper(vector<vector<int>>& questions, int index, vector<long long>& dp) {
    //         if (index >= questions.size()) return 0;
    //         if (dp[index] != -1) return dp[index];
    
    //         int next = index + 1 + questions[index][1];
    //         long long take = questions[index][0] + helper(questions, next, dp);
    //         long long skip = helper(questions, index + 1, dp);
    //         return dp[index] = max(take, skip);
    //     }
    
    // public:
    //     long long mostPoints(vector<vector<int>>& questions) {
    //         vector<long long> dp(questions.size(), -1);
    //         return helper(questions, 0, dp);
    //     }
    // };
    
    
    // Recursive solution - TLE without memo
    
    // class Solution {
    // private:
    //     void helper(vector<vector<int>>& questions, int index,
    //      long long &total, long long allowed, long long& result) {
    //         if (index >= questions.size()) {
    //             result = max(result, total);
    //             return;
    //         }
    
    
    //         if (allowed == 0) {
    //             total += questions[index][0];
    //             helper(questions, index + 1, total, allowed + questions[index][1], result);
    //             total -= questions[index][0];
    //         }    
    //         helper(questions, index + 1, total, max(0LL, allowed - 1), result);
    //     }
    
    // public:
    //     long long mostPoints(vector<vector<int>>& questions) {
    //         long long result = 0, total = 0;
    //         helper(questions, 0, total, 0, result);
    //         return result;
    //     }
    // };