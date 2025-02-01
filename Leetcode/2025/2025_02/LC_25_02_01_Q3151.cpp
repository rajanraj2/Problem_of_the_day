// https://leetcode.com/problems/special-array-i/description/?envType=daily-question&envId=2025-02-01
// 3151. Special Array I


class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] % 2 == nums[i] % 2) return false;
        }
        return true;
    }
};