// Link - https://leetcode.com/problems/sort-array-by-increasing-frequency/description/?envType=daily-question&envId=2024-07-23
// Sort Array by Increasing Frequency


class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        sort(nums.begin(), nums.end(), [&mpp](int a, int b) {
            if (mpp[a] == mpp[b]) {
                return a > b;
            }
            return mpp[a] < mpp[b];
        });
        return nums;
    }
};