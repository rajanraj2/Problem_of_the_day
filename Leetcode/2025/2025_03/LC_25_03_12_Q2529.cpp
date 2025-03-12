// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/?envType=daily-question&envId=2025-03-12
// 2529. Maximum Count of Positive Integer and Negative Integer


class Solution {
    private: 
        int binarySearch(vector<int> & nums, int target) {
            int left = 0, right = nums.size() - 1, result = nums.size();
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] < target) left = mid + 1;
                else {
                    result = mid;
                    right = mid - 1;
                }
            }
            return result;
        }
    
    public:
        int maximumCount(vector<int>& nums) {
            int pos = nums.size() - binarySearch(nums, 1);
            int neg = binarySearch(nums, 0);
            return max(pos, neg);
        }
    };
    
    
    // class Solution {
    // public:
    //     int maximumCount(vector<int>& nums) {
    //         int n = nums.size(), pos = 0, neg = 0;
    //         int left = 0, right = n - 1;
    //         while (left <= right) {
    //             int mid = left + (right - left) / 2;
    //             if (nums[mid] > 0) {
    //                 pos = n - mid;
    //                 right = mid - 1;
    //             }
    //             else left = mid + 1;
    //         }
    
    //         left = 0;
    //         right = n - 1;
    //         while (left <= right) {
    //             int mid = left + (right - left) / 2;
    //             if (nums[mid] >= 0) right = mid - 1;
    //             else {
    //                 neg = mid + 1;
    //                 left = mid + 1;
    //             }
    //         }
    //         return max(pos, neg);
    //     }
    // };
    
    
    // class Solution {
    // public:
    //     int maximumCount(vector<int>& nums) {
    //         int pos = 0, neg = 0;
    //         for (auto it : nums) {
    //             if (it > 0) pos++;
    //             else if (it < 0) neg++; 
    //         }
    //         return max(pos, neg);
    //     }
    // };