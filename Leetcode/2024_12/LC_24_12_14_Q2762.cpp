// https://leetcode.com/problems/continuous-subarrays/?envType=daily-question&envId=2024-12-14
// Continuous Subarrays


// Map & sliding window

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long count = 0;
        map<int, int> mpp;

        for (int left = 0, right = 0; right < nums.size(); right++) {
            mpp[nums[right]]++;
            while (left < right && mpp.rbegin()->first - mpp.begin()->first > 2) {
                int freq = --mpp[nums[left]];
                if (freq == 0) mpp.erase(nums[left]);
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
};


// Multiset & sliding window

// class Solution {
// public:
//     long long continuousSubarrays(vector<int>& nums) {
//         long long count = 0;
//         int left = 0;
//         multiset<int> window;

//         for (int right = 0; right < nums.size(); right++) {
//             window.insert(nums[right]);
//             while (*window.rbegin() - *window.begin() > 2) {
//                 window.erase(window.find(nums[left]));
//                 left++;
//             }
//             count += right - left + 1;
//         }
//         return count;
//     }
// };


// Brute Force - TLE

// class Solution {
// public:
//     long long continuousSubarrays(vector<int>& nums) {
//         int n = nums.size();
//         long long count = 0;
//         for (int i = 0; i < n; i++) {
//             int maxi = nums[i], mini = nums[i];
//             for (int j = i; j < n; j++) {
//                 maxi = max(maxi, nums[j]);
//                 mini = min(mini, nums[j]);
//                 if (maxi - mini > 2) break;
//                 count++;
//             }
//         }
//         return count;
//     }
// };