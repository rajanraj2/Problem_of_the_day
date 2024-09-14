// Link - https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/?envType=daily-question&envId=2024-09-14
// Longest Subarray with Maximum Bitwise AND


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int len = 0, result = 0;

        for (int it : nums) {
            if (it == maxi) {
                len++;
                result = max(result, len);
            }
            else len = 0;
        }

        return result;
    }
};