// https://leetcode.com/problems/house-robber-iv/?envType=daily-question&envId=2025-03-15
// 2560. House Robber IV


class Solution {
    public:
        bool check(vector<int>& nums, int k, int mid) {
            int count = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid) {
                    count++;
                    i++;
                }
                if (count >= k) return true;;
            }
            return false;
        }
    
        int minCapability(vector<int>& nums, int k) {
            int left = 1, right = *max_element(nums.begin(), nums.end());
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (check(nums, k, mid)) right = mid - 1;
                else left = mid + 1;
            }
            return left;
        }
    };