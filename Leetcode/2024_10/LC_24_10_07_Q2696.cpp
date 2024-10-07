// Link - https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/?envType=daily-question&envId=2024-10-07
// Minimum String Length After Removing Substrings


class Solution {
public:
    int minLength(string s) {   
        stack<char> st;
        for (char it : s) {
            if (!st.empty() && st.top() == 'A' && it == 'B') st.pop();
            else if (!st.empty() && st.top() == 'C' && it == 'D') st.pop();
            else st.push(it);
        }
        return st.size();
    }
};


// class Solution {
// public:
//     int minLength(string s) {
//         int i = 0;
//         if (s.size() < 2) return s.size();
        
//         while (i <= s.size() - 2 && s.size() > 1) {
//             string str = "";
//             str = s.substr(i, 2);

//             if (str == "AB" || str == "CD") {
//                 s.erase(i, 2);
//                 if (i > 0) i--;
//             }
//             else i++;
//         }

//         return s.size();
//     }
// };