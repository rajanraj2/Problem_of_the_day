// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/?envType=daily-question&envId=2024-12-28
// Maximum Sum of 3 Non-Overlapping Subarrays


// Tabulation

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ksum(n - k + 1, 0), L(n - 3 * k + 1, -1), R(n - 3 * k + 1, -1);
        int maxi = ksum[0] = accumulate(nums.begin(), nums.begin() + k, 0);
        L[0] = 0;

        for (int i = 1; i < n - k + 1; i++) {
            ksum[i] = ksum[i - 1] - nums[i - 1] + nums[i + k - 1];
            if (i > n - 3 * k) continue;
            if (maxi < ksum[i]) {
                maxi = ksum[i];
                L[i] = i;
            }
            else L[i] = L[i - 1];
        }

        maxi = ksum.back();
        R.back() = n - k;
        for (int i = n - k - 1; i >= 2 * k; i--) {
            if (maxi <= ksum[i]) {
                maxi = ksum[i];
                R[i - 2 * k] = i;
            }
            else R[i - 2 * k] = R[i + 1 - 2 * k];
        }

        vector<int> result(3, -1);
        int max3k = 0;
        for (int i = 0; i <= n - 3 *k; i++) {
            int sum3k = ksum[L[i]] + ksum[i + k] + ksum[R[i]];
            if (sum3k > max3k) {
                max3k = sum3k;
                result = {L[i], i + k, R[i]};
            }
        }
        return result;
    }
};