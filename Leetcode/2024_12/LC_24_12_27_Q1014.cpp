// https://leetcode.com/problems/best-sightseeing-pair/?envType=daily-question&envId=2024-12-27
// Best Sightseeing Pair


// Iterative dp/ greedy

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi = values[0];
        int result = 0;
        for (int j = 1; j < values.size(); j++) {
            result = max(result, maxi + values[j] - j);
            maxi = max(maxi, values[j] + j);
        }
        return result;
    }
};


// recursion

// class Solution {
// private:
//     int helper(int i, vector<int>& values, int& score, vector<int>& dp) {
//         if (i < 0) return 0;
//         if (dp[i] != 0) return dp[i];
//         int x = values[i];
//         int prev = helper(i - 1, values, score, dp);
//         score = max(score, prev + x - i);
//         return dp[i] = max(prev, x + i);
//     }

// public:
//     int maxScoreSightseeingPair(vector<int>& values) {
//         int n = values.size(), score = 0;
//         vector<int> dp(n, 0);
//         helper(n - 1, values, score, dp);
//         return score;
//     }
// };