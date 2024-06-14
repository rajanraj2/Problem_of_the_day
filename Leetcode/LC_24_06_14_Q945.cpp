// Link - https://leetcode.com/problems/minimum-increment-to-make-array-unique/?envType=daily-question&envId=2024-06-14
// Minimum Increment to make array unique


class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        sort(nums.begin(), nums.end());
        set<int> s;
        s.insert(nums[0]);

        for (int i = 1; i < n; i++) {
            if (s.find(nums[i]) != s.end()) {
                int initial = nums[i];
                nums[i] = nums[i - 1] + 1;
                int diff = nums[i] - initial;
                count += diff;
            }
            s.insert(nums[i]);
        }
        return count;
    }
};
