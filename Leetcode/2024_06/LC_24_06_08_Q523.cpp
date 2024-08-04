// Link - https://leetcode.com/problems/continuous-subarray-sum/?envType=daily-question&envId=2024-06-08
// Continuous Subarray Sum
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1 ; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        for (int i = 0; i < n; i++) {
            prefix[i] = prefix[i] % k;
        }
        map<int,int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            if (mp.find(prefix[i]) != mp.end()) {
                int index = mp[prefix[i]];
                int diff = i - index;
                if (diff >= 2) {
                    return true;
                }
            }
            else {
                mp[prefix[i]] = i;
            }
        }
        return false;
    }
};


// Brute Force approach (TLE)

// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         if (n == 1 ) return false;
//         for (int i = 0; i < n - 1; i++) {
//             int s = nums[i];
//             for (int j = i + 1; j < n; j++) {
//                 s += nums[j];
//                 if (s % k == 0) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };