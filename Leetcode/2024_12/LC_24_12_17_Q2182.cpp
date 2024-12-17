// https://leetcode.com/problems/construct-string-with-repeat-limit/?envType=daily-question&envId=2024-12-17
// Construct String with Repeat Limit


class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string result = "";
        vector<int> freq(26, 0);
        for (char ch : s) freq[ch - 'a']++;
        int i = 25, prev = -1;
        while (i >= 0) {
            if (freq[i] == 0) {
                i--;
                continue;
            }
            if (prev != -1) {
                result.push_back('a' + i);
                freq[i]--;
                i = prev;
                prev = -1;
                continue;
            }
            int count = repeatLimit;
            while (freq[i] > 0 && count > 0) {
                result.push_back('a' + i);
                freq[i]--;
                count--;
            } 
            if (freq[i] > 0) prev = i;
            else prev = -1;
            i--;
        }
        return result;
    }
};