// Link - https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/?envType=daily-question&envId=2024-07-11
// Reverse Substrings Between Each Pair of Parentheses


class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else if (s[i] == ')') {
                int open = st.top();
                st.pop();
                reverse(s.begin() + open + 1, s.begin() + i);
                s[open] = '*';
                s[i] = '*';
            }
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }   
};