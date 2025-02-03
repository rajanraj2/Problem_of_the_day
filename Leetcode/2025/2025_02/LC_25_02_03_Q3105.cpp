// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/?envType=daily-question&envId=2025-02-03
// 3105. Longest Strictly Increasing or Strictly Decreasing Subarray


class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi = 1, count = 1, count2 = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) count++;
            else count = 1;
            if (nums[i] < nums[i - 1]) count2++;
            else count2 = 1;
            maxi = max(maxi, max(count, count2));
        }
        return maxi;
    }
};