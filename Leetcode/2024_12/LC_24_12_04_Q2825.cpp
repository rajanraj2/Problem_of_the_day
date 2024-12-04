// https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/?envType=daily-question&envId=2024-12-04
// Make String a Subsequence Using Cyclic Increments


class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        int index2 = 0;
        for (int index1 = 0; index1 < m && index2 < n; index1++) {
            if (str1[index1] == str2[index2] || 
            str1[index1] + 1 == str2[index2] || 
            str1[index1] - 25 == str2[index2]) {
                index2++;
            }  
        }
        if (index2 == n) return true;
        else return false;

    }
};


// class Solution {
// public:
//     bool canMakeSubsequence(string str1, string str2) {
//         unordered_map<int, pair<char, char>> mpp;
//         int i = 0, index = 0, count = 0;
//         char next;
//         for (char ch : str1) {
//             if (ch == 'z') next = 'a';
//             else next = ch++;
//             mpp[i++] = {ch, next};
//         }
//         for (char ch : str2) {
//             while (true) {
//                 if (index >= i) break;
//                 if (mpp[index].first == ch || mpp[index].second == ch) {
//                     count++;
//                     index++;
//                     break;
//                 }
//                 index++;
//             }
//         }
//         if (count >= str2.size()) return true;
//         else return false;
//     }
// };