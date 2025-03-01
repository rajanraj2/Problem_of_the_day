class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int last = nums[0], n = nums.size(), j = 0;
            vector<int> result(n, 0);
    
            for (int i = 1; i < n; i++) {
                if (last == nums[i]) {
                    if (last != 0) result[j++] = last * 2;
                    last = 0;
                }
                else {
                    if (last != 0) result[j++] = last;
                    last = nums[i];
                }
            }
            if (last != 0) result[j] = last;
            return result;
        }
    };
    
    
    // class Solution {
    // public:
    //     vector<int> applyOperations(vector<int>& nums) {
    //         int n = nums.size();
    //         for (int i = 0; i < n - 1; i++) {
    //             if (nums[i] == nums[i + 1]) {
    //                 nums[i] *= 2;
    //                 nums[i + 1] = 0;
    //             }
    //         }
    
    //         int i = -1, j = 0;
    //         while (j < n) {
    //             if (nums[j] == 0) {
    //                 if (i == -1) i = j;
    //             }
    //             else if (i != -1) {
    //                 swap(nums[i], nums[j]);
    //                 i++;
    //             }
    //             j++;
    //         }
    
    //         return nums;
    //     }
    // };