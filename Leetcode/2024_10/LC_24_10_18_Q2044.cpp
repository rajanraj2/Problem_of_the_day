// Link - https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/?envType=daily-question&envId=2024-10-18
// Count Number of Maximum Bitwise-OR Subsets


class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int val = 0, result = 0;
        int n = nums.size();
        for (auto it : nums) val = val | it;

        int total = 1 << n;
        for (int i = 0; i < total; i++) {
            int temp = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) temp = temp | nums[j];
            }
            if (temp == val) result++;
        }

        return result;
    }
};