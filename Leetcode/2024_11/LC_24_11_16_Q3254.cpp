// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/?envType=daily-question&envId=2024-11-16
// Find the Power of K size subarrays I


class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n - k + 1, -1);

        for (int i = 0; i <= n - k; i++) {
            int j = i;
            while (j < i + k - 1) {
                if (nums[j] + 1 != nums[j + 1]) break;
                j++;
            }
            if (j >= i + k - 1) result[i] = nums[j];
        }

        return result;
    }
};