// Link - https://leetcode.com/problems/subarray-sums-divisible-by-k/description/?envType=daily-question&envId=2024-06-09
// Subarray Sums Divisible by K

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int remainder = sum % k;
            if (remainder < 0) {
                remainder += k;
            }
            if (mp.find(remainder) != mp.end()) {
                count += mp[remainder];
            }
            mp[remainder]++;
        }
        return count;
    }
};


// Brute Forece Approach (TLE)

// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
//         int n = nums.size();
//         int s = 0;
//         int count = 0;
//         for (int i = 0; i < n; i++) {
//             s = nums[i];
//             for (int j = i + 1; j < n; j++) {
//                 if ((s % k) == 0) {
//                     count++;
//                 }
//                 s += nums[j];
//             }
//             if ((s % k) == 0) {
//                 count++;
//             }
//         }
//         return count;
//     }
// };