// Link - https://leetcode.com/problems/parsing-a-boolean-expression/description/?envType=daily-question&envId=2024-10-20
// Parsing a Boolean Expression


class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char ch : expression) {
            if (ch == ',' | ch == '(') continue;
            if (ch == 't' | ch == 'f' | ch == '!' | ch == '&' | ch == '|') st.push(ch);
            else if (ch == ')') {
                bool hasTrue = false, hasFalse = false;

                while (st.top() != '!' & st.top() != '&' & st.top() != '|') {
                    char top = st.top();
                    st.pop();
                    if (top == 't') hasTrue = true;
                    if (top == 'f') hasFalse = true;
                }

                char oper = st.top();
                st.pop();
                if (oper == '!') st.push(hasTrue ? 'f' : 't');
                else if (oper == '&') st.push(hasFalse ? 'f' : 't');
                else st.push(hasTrue ? 't' : 'f');
            }
        }

        return st.top() == 't';
    }
};