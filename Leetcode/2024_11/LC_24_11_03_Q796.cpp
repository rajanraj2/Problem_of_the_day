// Link - https://leetcode.com/problems/rotate-string/?envType=daily-question&envId=2024-11-03
// Rotate string


class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        string str = s + s;

        if (str.find(goal) != string::npos) return true;
        return false;
    }
};


// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         int n = s.size();
//         for (int i = 0; i < n; i++) {
//             string str = s.substr(i, n - i) + s.substr(0, i);
//             if (str == goal) return true;
//         }
//         return false;
//     }
// };