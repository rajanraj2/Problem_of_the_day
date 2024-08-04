// Link - https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/?envType=daily-question&envId=2024-06-23
// Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int left = 0, right = 0;
        int longest = 0;
        
        while (right < nums.size()) {
            // Maintain the decreasing deque for max values
            while (!maxDeque.empty() && nums[right] > maxDeque.back()) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(nums[right]);

            // Maintain the increasing deque for min values
            while (!minDeque.empty() && nums[right] < minDeque.back()) {
                minDeque.pop_back();
            }
            minDeque.push_back(nums[right]);
            
            // Check if the current window is valid
            if (maxDeque.front() - minDeque.front() <= limit) {
                longest = max(longest, right - left + 1);
                right++;
            } else {
                // If not valid, move the left pointer
                if (nums[left] == maxDeque.front()) maxDeque.pop_front();
                if (nums[left] == minDeque.front()) minDeque.pop_front();
                left++;
                right++;
            }
        }
        
        return longest;
    }
};