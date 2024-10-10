// Link - https://leetcode.com/problems/maximum-width-ramp/description/?envType=daily-question&envId=2024-10-10
// Maximum Width Ramp


class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;

        for (int i = 0; i < n; i++) {
            if (s.empty() || nums[s.top()] > nums[i]) s.push(i);
        }
        int maxWidth = 0;

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] <= nums[i]) {
                maxWidth = max(maxWidth, i - s.top());
                s.pop();
            }
        }

        return maxWidth;
    }
};