// Link - https://leetcode.com/problems/different-ways-to-add-parentheses/?envType=daily-question&envId=2024-09-19
// Different Ways to Add Parentheses


class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        for (int i = 0; i < expression.size(); ++i) {
            char oper = expression[i];
            if (oper == '+' || oper == '-' || oper == '*') {
                vector<int> s1 = diffWaysToCompute(expression.substr(0, i));
                vector<int> s2 = diffWaysToCompute(expression.substr(i + 1));
                for (int a : s1) {
                    for (int b : s2) {
                        if (oper == '+') res.push_back(a + b);
                        else if (oper == '-') res.push_back(a - b);
                        else if (oper == '*') res.push_back(a * b);
                    }
                }
            }
        }
        if (res.empty()) res.push_back(stoi(expression));
        return res;
    }
};


// class Solution {
// private:
//     vector<int> compute(vector<int>& left, vector<int>& right, char op) {
//         vector<int> result;
//         for (int l : left) {
//             for (int r : right) {
//                 if (op == '+') result.push_back(l + r);
//                 else if (op == '-') result.push_back(l - r);
//                 else if (op == '*') result.push_back(l * r);
//             }
//         }
//         return result;
//     }

//     vector<int> helper(string expression, int start, int end) {
//         vector<int> result;
//         bool isNumber = true;

//         for (int i = start; i <= end; i++) {
//             char ch = expression[i];
//             if (ch == '+' || ch == '-' || ch == '*') {
//                 isNumber = false;

//                 vector<int> left = helper(expression, start, i - 1);
//                 vector<int> right = helper(expression, i + 1, end);

//                 vector<int> combined = compute(left, right, ch);
//                 result.insert(result.end(), combined.begin(), combined.end());
//             }
//         }

//         if (isNumber) {
//             result.push_back(stoi(expression.substr(start, end - start + 1)));
//         }

//         return result;
//     }

// public:
//     vector<int> diffWaysToCompute(string expression) {
//         return helper(expression, 0, expression.size() - 1);
//     }
// };
