// https://leetcode.com/problems/construct-k-palindrome-strings/?envType=daily-question&envId=2025-01-11
// Construct K Palindrome Strings


class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) return false;
        int bitmask = 0;

        for (char ch : s) bitmask ^= (1 << (ch - 'a'));

        int count = 0, n = bitmask;
        while (n) {
            n = n & (n - 1);
            count++;
        }
        return count <= k;
    }
};


// class Solution {
// public:
//     bool canConstruct(string s, int k) {
//         if (s.size() < k) return false;
//         vector<int> arr(26, 0);
//         int count = 0;

//         for (int i = 0; i < s.size(); i++) arr[s[i] - 'a']++;
//         for (int it : arr) if (it & 1) count++;

//         if (count <= k) return true;
//         return false;
//     }
// };