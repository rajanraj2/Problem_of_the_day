// https://leetcode.com/problems/longest-nice-subarray/?envType=daily-question&envId=2025-03-18
// 2401. Longest Nice Subarray


// O(n)

class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int n = nums.size(), left = 0, mask = 0, result = 0;
            for (int right = 0; right < n; right++) {
                while (mask & nums[right]) mask &= ~nums[left++];
                mask |= nums[right];
                result = max(result, right - left + 1);
            }
            return result;
        }
    };
    
    
    // O(n^2)
    
    // class Solution {
    // public:
    //     int longestNiceSubarray(vector<int>& nums) {
    //         int n = nums.size(), prev = nums[0], result = 1, count = 1, last = 0;
    //         bool flag = true;
    //         for (int i = 1; i < n; i++) {
    //             if ((prev & nums[i]) == 0) {
    //                 if (flag) {
    //                     last = i;
    //                     flag = false;
    //                 }
    //                 count++;
    //                 prev = prev | nums[i];
    //             }
    //             else {
    //                 if (!flag) i = last;
    //                 flag = true;
    //                 count = 1;
    //                 prev = nums[i];
    //             }
    //             result = max(result, count);
    //         }
    //         return result;
    //     }
    // };