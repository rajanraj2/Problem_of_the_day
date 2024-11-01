// Link - https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/?envType=daily-question&envId=2024-11-01
// Delete Characters to Make Fancy String


class Solution {
public:
    string makeFancyString(string s) {
        if (s.size() < 3) return s;

        int j = 2;
        for (int i = 2; i < s.size(); i++) {
            if (s[i] != s[j - 1] || s[i] != s[j - 2]) s[j++] = s[i];
        }

        s.resize(j);
        return s;
    }
};


// class Solution {
// public:
//     string makeFancyString(string s) {
//         if (s.size() <= 2) return s;
//         char prev1 = s[0], prev2 = s[1];
//         string result = "";
//         result += prev1;
//         result += prev2;

//         for (int i = 2; i < s.size(); i++) {
//             char it = s[i];
//             if (it == prev1 && it == prev2) continue;
//             else {
//                 prev1 = prev2;
//                 prev2 = it; 
//                 result += it;
//             }
//         }

//         return result;
//     }
// };
