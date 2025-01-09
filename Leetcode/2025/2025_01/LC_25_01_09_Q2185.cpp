// https://leetcode.com/problems/counting-words-with-a-given-prefix/?envType=daily-question&envId=2025-01-09
// Counting Words With A Given Prefix


class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].find(pref) == 0) count++;
        }
        return count;
    }
};