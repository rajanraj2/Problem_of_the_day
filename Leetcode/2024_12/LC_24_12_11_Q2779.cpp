// https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/?envType=daily-question&envId=2024-12-11
// Maximum Beauty of an Array After Applying Operation


// Sweep

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int result = 0;
        if (nums.size() == 1) return 1;
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> arr(maxi + 1, 0);
        
        for (int i = 0; i < nums.size(); i++) {
            arr[max(nums[i] - k, 0)]++;
            arr[min(nums[i] + k + 1, maxi)]--;
        }

        int sum = 0;
        for (int it : arr) {
            sum += it;
            result = max(result, sum);
        }
        return result;
    }
};


// Sliding Window

// class Solution {
// public:
//     int maximumBeauty(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         int right = 0;
//         int result = 0;

//         for (int left = 0; left < nums.size(); left++) {
//             while (right < nums.size() && nums[right] - nums[left] <= 2 * k) right++;
//             result = max(result, right - left);
//         }
//         return result;
//     }
// };


// Binary Search

// class Solution {
// public:
//     int maximumBeauty(vector<int>& nums, int k) {
//         int n = nums.size();
//         int result = 0;
//         vector<pair<int, int>> arr(n);
//         int prev = INT_MIN;
//         bool flag = true;
//         for (int i = 0; i < n; i++) {
//             arr[i] = {nums[i] - k, nums[i] + k};
//             if (prev == INT_MIN) prev = nums[i];
//             else if (prev != nums[i]) flag = false;
//         }
//         if (flag) return n;

//         sort(arr.begin(), arr.end());
//         for (int i = 0; i < n; i++) {
//             int left = i, right = n - 1;
//             while (left <= right) {
//                 int mid = left + (right - left) / 2;
//                 if (arr[mid].first <= arr[i].second) left = mid + 1;
//                 else right = mid - 1;
//             }
//             int count = right - i + 1;
//             result = max(result, count);
//         }
//         return result;
//     }
// };