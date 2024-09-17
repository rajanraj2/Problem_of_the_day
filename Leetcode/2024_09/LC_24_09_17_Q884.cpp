// Link - https://leetcode.com/problems/uncommon-words-from-two-sentences/?envType=daily-question&envId=2024-09-17
// Uncommon Words from Two Sentences


class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> mpp;
        vector<string> result, words;
        string word = "";
        string s3 = s1 + " " + s2;

        for (char it : s3) {
            if (it == ' ') {
                words.push_back(word);
                mpp[word]++;
                word = "";
            }
            else word += it;
        }
        words.push_back(word);
        mpp[word]++;

        for (string word : words) {
            if (mpp[word] == 1) result.push_back(word);
        }
        return result;
    }
};