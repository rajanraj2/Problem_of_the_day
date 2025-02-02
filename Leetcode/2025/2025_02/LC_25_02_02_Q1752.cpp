// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
// 1752. Check if Array Is Sorted and Rotated


class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) count++;
            if (count > 1) return false;
        }
        if (count == 1 && nums.back() > nums[0]) return false;
        return true;
    }
};