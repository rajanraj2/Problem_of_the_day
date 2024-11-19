// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/?envType=daily-question&envId=2024-11-19
// Maximum Sum of Distinct Subarrays with Length K


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0, result = 0;
        int left = 0;
        unordered_set<int> st;

        for (int right = 0; right < n; right++) {
            if (st.find(nums[right]) == st.end()) {
                sum += nums[right];
                st.insert(nums[right]);

                if (right - left + 1 == k) {
                    result = max(result, sum);
                    sum -= nums[left];
                    st.erase(nums[left]);
                    left++;
                }
            }
            else {
                while (nums[left] != nums[right]) {
                    sum -= nums[left];
                    st.erase(nums[left]);
                    left++;
                }
                left++;
            }
        }
        return result;
    }
};


// Brute force

// class Solution {
// public:
//     long long maximumSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         long long result = 0;
//         int left = 0, right = k + 1;
//         for (int i = 0; i <= n - k; i++) {
//             int len = 0;
//             int j = i;
//             long long sum = 0;
//             set<int> st;
//             while (len < k && j < n) {
//                 if (st.find(nums[j]) != st.end()) break;
//                 else {
//                     len++;
//                     st.insert(nums[j]);
//                     sum += nums[j];
//                 }
//                 j++;
//             }
//             if (len >= k) result =  max(result, sum);
//         }
//         return result;
//     }
// };