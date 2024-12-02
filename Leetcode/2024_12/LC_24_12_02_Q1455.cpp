// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/?envType=daily-question&envId=2024-12-02
// Check If a Word Occurs As a Prefix of Any Word in a Sentence


class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = searchWord.size();
        int index = 1;
        string word = "";

        for (char ch : sentence) {
            if (ch == ' ') {
                if (word.size() >= n && searchWord == word.substr(0, n)) return index;
                word = "";
                index++;
            }
            else word += ch;
        }

        if (word.size() >= n && searchWord == word.substr(0, n)) return index;
        return -1;
    }
};


// class Solution {
// public:
//     int isPrefixOfWord(string sentence, string searchWord) {
//         int n = searchWord.size();
//         vector<string> arr;
//         string s = "";
//         for (char it : sentence) {
//             if (it == ' ') {
//                 arr.push_back(s);
//                 s = "";
//                 continue;
//             }
//             s += it;
//         }

//         if (!s.empty()) arr.push_back(s);
//         for (int it = 0; it < arr.size(); it++) {
//             for (int i = 0; i < arr[it].size(); i++) {
//                 if (arr[it][i] != searchWord[i]) break;
//                 if (i >= n) break;
//                 if (i == n - 1 && searchWord == arr[it].substr(0, n)) return it + 1;
//             }
//         }
//         return -1;
//     }
// };