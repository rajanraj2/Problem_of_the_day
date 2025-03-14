// https://leetcode.com/problems/zero-array-transformation-ii/?envType=daily-question&envId=2025-03-13
// 3356. Zero Array Transformation II


class Solution {
    private:
        bool check(vector<int>& nums, vector<vector<int>>& queries, int mid) {
            int n = nums.size(), sum = 0;
            vector<int> pre(n + 1, 0);
            for (int i = 0; i <= mid; i++) {
                int start = queries[i][0], end = queries[i][1], val = queries[i][2];
                pre[start] -= val;
                pre[end + 1] += val;
            }
            
            for (int i = 0; i < n; i++) {
                sum += pre[i];
                pre[i] = max(0, nums[i] + sum);
                if (pre[i] > 0) return false;
            }
            return true;
        }
    
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n = nums.size(), result = -1;
            int left = -1, right = queries.size() - 1;
    
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (check(nums, queries, mid)) {
                    result = mid + 1;
                    right = mid - 1;
                }
                else left = mid + 1;
            }
            return result;
        }
    };
    
    
    // Brute Force - TLE
    
    // class Solution {
    // public:
    //     int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    //         int n = nums.size(), count = 0;
    //         vector<int> arr(n, 0);
    
    //         for (auto it : queries) {
    //             if (nums == arr) return count;
    //             int start = it[0], end = it[1], val = it[2];
    //             for (int i = start; i <= end; i++) {
    //                 nums[i] = max(0, nums[i] - val);
    //             }
    //             count++;
    //         }
    //         if (nums == arr) return count;
    //         return -1;
    //     }
    // };