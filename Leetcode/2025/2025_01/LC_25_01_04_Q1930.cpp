// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/?envType=daily-question&envId=2025-01-04
// Unique Length-3 Palindromic Subsequences


class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, pair<int, int>> mpp;
        set<string> st;

        for (int i = 0; i < s.size(); i++) {
            if (mpp.find(s[i]) == mpp.end()) mpp[s[i]] = {i, i};
            else mpp[s[i]] = {mpp[s[i]].first, i};
        }

        for (auto it : mpp) {
            int end = it.second.second, start = it.second.first;
            for (int i = start + 1; i < end; i++) {
                string str = "";
                str += s[start];
                str += s[i];
                str += s[end];
                st.insert(str);
            }
        }
        return st.size();
    }
};


// Brute Force : TLE

// class Solution {
// public:
//     int countPalindromicSubsequence(string s) {
//         int n = s.size();
//         set<string> st;
//         for (int i = 0; i < n - 2; i++) {
//             for (int j = i + 1; j < n - 1; j++) {
//                 for (int k = j + 1; k < n; k++) {
//                     if (s[k] == s[i]) {
//                         string seq = "";
//                         seq += s[i];
//                         seq += s[j];
//                         seq += s[k];
//                         if (seq.size() == 3) st.insert(seq); 
//                     }
//                 }
//             }
//         }
//         return st.size();
//     }
// };