// https://leetcode.com/problems/clear-digits/?envType=daily-question&envId=2025-02-10
// 3174. Clear Digits


class Solution {
public:
    string clearDigits(string s) {
        int i = 0;
        while (i < s.size()) {
            if (s[i] < 'a' || s[i] > 'z') {
                if (i > 0) {
                    i--;
                    s.erase(s.begin() + i);
                }
                s.erase(s.begin() + i);
            }
            else i++;
        }
        
        return s;
    }
};