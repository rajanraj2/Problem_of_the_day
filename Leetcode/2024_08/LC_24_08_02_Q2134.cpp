// Link - https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/?envType=daily-question&envId=2024-08-02
// Minimum Swaps to Group All 1's Together II


class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int onesCount = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) onesCount++;
        }

        if (onesCount == 0 || onesCount == 1) return 0;

        int minSwaps = INT_MAX;
        int zero = 0;

        for (int i = 0; i < onesCount; i++) {
            if (nums[i] == 0) zero++;
        }
        minSwaps = zero;

        for (int i = 1; i < n; i++) {
            if (nums[(i - 1) % n] == 0) zero--;
            if (nums[(i + onesCount - 1) % n] == 0) zero++;
            minSwaps = min(minSwaps, zero);
        }

        return minSwaps;
    }
};