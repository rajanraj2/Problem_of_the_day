// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/?envType=daily-question&envId=2025-01-12
// Check if a Parentheses String Can Be Valid


class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2) return false;
        int open = 0, close = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || locked[i] == '0') open++;
            else open--;
            if (open < 0) return false;
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')' || locked[i] == '0') close++;
            else close--;
            if (close < 0) return false;
        }
        return true;
    }
};


// class Solution {
// public:
//     bool canBeValid(string s, string locked) {
//         if (s.size() % 2) return false;
//         stack<char> st;

//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == '(') st.push(s[i]);
//             else if (!st.empty()) st.pop();
//             else if (locked[i] == '0') st.push('(');
//             else return false;
//         }

//         return st.empty();              
//     }
// };