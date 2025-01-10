// https://leetcode.com/problems/word-subsets/?envType=daily-question&envId=2025-01-10
// Word Subsets


class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> arr(26, 0);
        vector<string> result;

        for (auto it : words2) {
            vector<int> word(26);
            for (int i = 0; i < it.size(); i++) {
                word[it[i] - 'a']++;
            }

            for (int i = 0; i < 26; i++) {
                arr[i] = max(arr[i], word[i]);
            }
        }

        for (string it : words1) {
            vector<int> check(26, 0);
            bool flag = true;
            for (int i = 0; i < it.size(); i++) {
                check[it[i] - 'a']++; 
            }
            for (int i = 0; i < 26; i++) {
                if (check[i] < arr[i]) flag = false;
                if (!flag) break;
            }
            if (flag) result.push_back(it);
        }
        return result;
    }
};