// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/?envType=daily-question&envId=2024-12-07
// Minimum Limit of Balls in a Bag


class Solution {
private:
    bool isPossible(int maxBalls, vector<int>& nums, int oper) {
        int totalOper = 0;
        for (int i = 0; i < nums.size(); i++) {
            int operations = ceil((double)nums[i] / (double)maxBalls) - 1;
            totalOper += operations;
        }
        if (totalOper > oper) return false;
        return true;
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        sort(nums.begin(), nums.end());
        int left = 1, right = *max_element(nums.begin(), nums.end());

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(mid, nums, maxOperations)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};