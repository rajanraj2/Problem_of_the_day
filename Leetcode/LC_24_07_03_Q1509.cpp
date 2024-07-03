// Link - https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/?envType=daily-question&envId=2024-07-03
// Minimum Difference Between Largest and Smallest Value in Three Moves


class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mini = INT_MAX;
        if (n <= 4) return 0;

        mini = min(mini, nums[n - 4] - nums[0]);
        mini = min(mini, nums[n - 1] - nums[3]);
        mini = min(mini, nums[n - 2] - nums[2]);
        mini = min(mini, nums[n - 3] - nums[1]);

        return mini;
    }
};


// class Solution {
// public:
//     int minDifference(vector<int>& nums) {
//         if(nums.size() <= 4) {
//             return 0;
//         }
//         sort(nums.begin(), nums.end());
//         int k = nums.size() - 3;
//         int ans = nums.back() - nums[0];
//         for(int i = k - 1; i < nums.size(); i++) {
//             ans = min(ans, nums[i] - nums[i - k + 1]);
//         }
//         return ans;
//     }
// };