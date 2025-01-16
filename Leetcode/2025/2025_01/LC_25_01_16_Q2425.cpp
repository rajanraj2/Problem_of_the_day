// https://leetcode.com/problems/bitwise-xor-of-all-pairings/?envType=daily-question&envId=2025-01-16
// Bitwise XOR of All Pairings


class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int result = 0, a = 0, b = 0;
        for (int &it : nums1) a ^= it;
        for (int &it : nums2) b ^= it;
        if (nums2.size() % 2) result ^= a;
        if (nums1.size() % 2) result ^= b;
        return result;
    }
};


// Brute Force - TLE

// class Solution {
// public:
//     int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
//         int result = 0;
//         for (int &it1 : nums1) {
//             for (int &it2 : nums2) {
//                 result ^= (it1 ^ it2);
//             }
//         }
//         return result;
//     }
// };