// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/?envType=daily-question&envId=2025-02-11
// 1910. Remove All Occurrences of a Substring


class Solution {
public:
    string removeOccurrences(string s, string part) {
        string stack = "";
        int pz = part.size(), sz = 0;
        for (char ch : s) {
            stack += ch;
            sz++;
            if (sz >= pz && stack.ends_with(part)) {
                sz -= pz;
                stack.resize(sz);
            }
        }
        return stack;
    }
};


// class Solution {
// public:
//     string removeOccurrences(string s, string part) {
//         int p = part.size();
//         while (true) {
//             int i = -1;
//             i = s.find(part);
//             if (i != -1) s.erase(i, p);
//             else break;
//         }
//         return s;
//     }
// };