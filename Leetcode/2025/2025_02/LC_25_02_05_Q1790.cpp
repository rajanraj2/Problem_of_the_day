// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/?envType=daily-question&envId=2025-02-05
// 1790. Check if One String Swap Can Make Strings Equal


class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        char a, b;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (count == 0) {
                    a = s1[i];
                    b = s2[i];
                }
                else if (s1[i] != b || s2[i] != a) return false;
                count++;
                if (count > 2) return false;
            }
        }
        if (count == 1) return false;
        return true;
    }
};