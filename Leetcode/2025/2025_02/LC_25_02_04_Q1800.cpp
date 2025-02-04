// https://leetcode.com/problems/maximum-ascending-subarray-sum/?envType=daily-question&envId=2025-02-04
// 1800. Maximum Ascending Subarray Sum


class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = nums[0], sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] < nums[i]) sum += nums[i];
            else sum = nums[i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};