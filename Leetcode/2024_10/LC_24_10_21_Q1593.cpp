// Link - https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/?envType=daily-question&envId=2024-10-21
// Split a String Into the Max Number of Unique Substrings


class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return backtrack(0, s, seen);
    }
private:
    int backtrack(int start, const string& s, unordered_set<string>& seen) {
        if (start == s.size()) {
            return 0;
        }
        int maxSplits = 0;
        for (int end = start + 1; end <= s.size(); ++end) {
            string substring = s.substr(start, end - start);
            if (seen.find(substring) == seen.end()) {
                seen.insert(substring);
                maxSplits = max(maxSplits, 1 + backtrack(end, s, seen));
                seen.erase(substring);
            }
        }
        return maxSplits;
    }
};


// class Solution {
// public:
//     int maxUniqueSplit(string s) {
//         set<string> st;
//         int i = 0, len = 1, result = 0;

//         while ((i + len - 1) < s.size()) {
//             string str = s.substr(i, len);
//             if (st.find(str) == st.end()) {
//                 st.insert(str);
//                 result++;
//                 i = i + len;
//                 len = 1;
//             }
//             else {
//                 len++;
//                 if ((i + len - 1) >= s.size()) {
//                     cout << "YES" << endl;
//                     string str = s.substr(i, len - 1);
//                     if (st.find(str) == st.end()) result++;
//                 }
//             }
//         }

//         return result;
//     }
// };