// Link - https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/?envType=daily-question&envId=2024-10-09
// Minimum Add to Make Parentheses Valid


class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st1, st2;
        int result = 0;
        for (char it : s) {
            if (it == '(') st1.push(it);
            else if (!st1.empty() && it == ')') st1.pop();
            else result++;
        }
        result += st1.size();
        return result;
    }
};