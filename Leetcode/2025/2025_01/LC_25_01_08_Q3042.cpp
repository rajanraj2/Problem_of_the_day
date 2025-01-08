// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/?envType=daily-question&envId=2025-01-08
// Count Prefix And Suffix Pairs I


class Solution {
public:
    bool isPrefixAndSuffix(string &str1, string &str2) {
        int s1 = str1.size(), s2 = str2.size();
        if (s2 < s1) return false;
        bool ans = true;
        if (str1 != str2.substr(0, s1)) ans = false;
        if (!ans) return ans;
        if (str1 != str2.substr(s2 - s1, s1)) ans = false;
        return ans;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (isPrefixAndSuffix(words[i], words[j])) count++;
            }
        }
        return count;
    }
};