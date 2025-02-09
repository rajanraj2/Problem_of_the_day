// https://leetcode.com/problems/count-number-of-bad-pairs/?envType=daily-question&envId=2025-02-09
// 2364. Count Number of Bad Pairs


class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long good = 0, n = nums.size();
        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            int val = nums[i] - i;
            good += mpp[val];
            mpp[val]++;
        }
        return (n * (n - 1)) / 2 - good;
    }
};