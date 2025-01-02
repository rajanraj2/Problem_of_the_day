// https://leetcode.com/problems/count-vowel-strings-in-ranges/?envType=daily-question&envId=2025-01-02
// count vowel strings in ranges


class Solution {
private:
    bool isVowel(string s) {
        if ((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') && 
        (s.back() == 'a' || s.back() =='e' || s.back() =='i' || s.back() =='o' || s.back() =='u')) {
            return true;
        }
        return false;
    }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int q = queries.size(), n = words.size();
        vector<int> result(q), arr(n);
        arr[0] = isVowel(words[0]);
        for (int i = 1; i < n; i++) {
            arr[i] = arr[i - 1] + isVowel(words[i]);
        }

        for (int i = 0; i < q; i++) {
            result[i] = arr[queries[i][1]];
            if (queries[i][0] > 0) result[i] -= arr[queries[i][0] - 1];
        }
        return result;
    }
};