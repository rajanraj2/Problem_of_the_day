// https://leetcode.com/problems/partition-array-according-to-given-pivot/?envType=daily-question&envId=2025-03-03
// 2161. Partition Array According to Given Pivot


class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int n  = nums.size();
            vector<int> result(n, pivot);
            int i = 0, j = n - 1;
            int left = 0, right = n - 1;
    
            while (left < n || right >= 0) {
                if (left < n && nums[left] < pivot) result[i++] = nums[left];
                if (right >= 0 && nums[right] > pivot) result[j--] = nums[right];
                left++;
                right--;
            }
            return result;
        }
    };
    
    
    // class Solution {
    // public:
    //     vector<int> pivotArray(vector<int>& nums, int pivot) {
    //         int n = nums.size(), count = 0;
    //         vector<int> result;
    //         result.reserve(n);
    
    //         for (int i = 0; i < n; i++) {
    //             if (nums[i] < pivot) result.push_back(nums[i]);
    //             else if (nums[i] == pivot) count++;
    //         }
    
    //         for (int i = 0; i < count; i++) result.push_back(pivot);
    //         for (int i = 0; i < n; i++) {
    //             if (nums[i] > pivot) result.push_back(nums[i]);
    //         }
    
    //         return result;
    //     }
    // };