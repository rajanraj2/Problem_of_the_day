// https://leetcode.com/problems/number-of-ways-to-split-array/?envType=daily-question&envId=2025-01-03
// Number of Ways to Split Array


class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long left = 0;
        long long right = accumulate(nums.begin(), nums.end(), 0LL);
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            left += nums[i];
            right -= nums[i];
            if (left >= right) count++;
        }
        return count;
    }
};


// class Solution {
// public:
//     int waysToSplitArray(vector<int>& nums) {
//         int n = nums.size(), count = 0;
//         long long total = 0;
//         vector<long long> pre(n);
//         for (int i = 0; i < n; i++) {
//             pre[i] = pre[max(0, i - 1)] + (long long)nums[i];
//             total += nums[i];
//         }

//         for (int i = 0; i < n - 1; i++) {
//             if (pre[i] >= (total - pre[i])) count++;
//         }
//         return count;
//     }
// };