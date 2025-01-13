// https://leetcode.com/problems/minimum-length-of-string-after-operations/?envType=daily-question&envId=2025-01-13
// Minimum Length of String After Applying Operations


class Solution {
public:
    int minimumLength(string s) {
        int result = 0;
        vector<int> arr(26, 0);
        for (char ch : s) arr[ch - 'a']++;
        for (int it : arr) {
            if (it < 3) result += it;
            else if (it % 2) result++;
            else result += 2;
        }
        return result;
    }
};