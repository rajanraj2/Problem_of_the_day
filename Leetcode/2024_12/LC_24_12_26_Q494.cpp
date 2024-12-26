// https://leetcode.com/problems/target-sum/description/?envType=daily-question&envId=2024-12-26
// Target Sum


class Solution {
private:
    void helper(int i, vector<int>& nums, int target, int sum, int& count) {
        if (i >= nums.size()) {
            if (sum == target) count++;
            return;
        }
        sum += nums[i];
        helper(i + 1, nums, target, sum, count);
        sum -= (2 * nums[i]);
        helper(i + 1, nums, target, sum, count);
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        helper(0, nums, target, 0, count);
        return count;
    }
};