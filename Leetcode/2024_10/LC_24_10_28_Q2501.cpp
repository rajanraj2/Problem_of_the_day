// Link - https://leetcode.com/problems/longest-square-streak-in-an-array/?envType=daily-question&envId=2024-10-28
// Longest square streak in an array


class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<int, int> mpp;
        sort(nums.begin(), nums.end());
        int result = -1;
        for (int it : nums) {
            int sq = sqrt(it);
            if (sq * sq == it && mpp.find(sq) != mpp.end()) {
                mpp[it] = mpp[sq] + 1;
                result = max(result, mpp[it]);
            }
            else mpp[it] = 1;
        }
        return result;
    }
};