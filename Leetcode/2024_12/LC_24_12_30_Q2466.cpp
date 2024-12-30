// https://leetcode.com/problems/count-ways-to-build-good-strings/description/?envType=daily-question&envId=2024-12-30
// Count Ways to Build good Strings


// tabulation

class Solution {
    public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int mod = 1e9 + 7;
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        int result = 0;

        for (int i = 1; i <= high; i++) {
            if (i >= zero) dp[i] = (dp[i] + dp[i - zero]) % mod;
            if (i >= one) dp[i] = (dp[i] + dp[i - one]) % mod;
            if (i >= low) result = (result + dp[i]) % mod;
        }
        return result;
    }
};


// memoization

// class Solution {
// private:
//     int mod = 1e9 + 7;
//     int solve(int s, int low, int high, int zero, int one, unordered_map<int, int> &memo) {
//         if (s > high) return 0;
//         if (memo.find(s) != memo.end()) return memo[s];

//         int count = (s >= low && s <= high) ? 1 : 0;
//         count = (count + solve(s + zero, low, high, zero, one, memo)) % mod;
//         count = (count + solve(s + one, low, high, zero, one, memo)) % mod;
//         return memo[s] = count;
//     }

// public:
//     int countGoodStrings(int low, int high, int zero, int one) {
//         unordered_map<int, int> memo;
//         return solve(0, low, high, zero, one, memo);
//     }
// };
