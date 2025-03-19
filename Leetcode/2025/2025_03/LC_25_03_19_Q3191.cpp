// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/?envType=daily-question&envId=2025-03-19
// 3191. Minimum Operations to Make Binary Array Elements Equal to One I


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0, n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] == 0) {
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                result++;
            }
        }
        if (nums[n - 1] == 0 || nums[n - 2] == 0) result= -1;
        return result;
    }
};