// https://leetcode.com/problems/adding-spaces-to-a-string/?envType=daily-question&envId=2024-12-03
// Adding Spaces to a String


class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result = "";
        int index = 0, prev = 0, val = 0;
        for (int i = 0; i < spaces.size(); i++) {
            val = spaces[i] - prev;
            result += s.substr(index, val);
            result += " ";
            prev = spaces[i];
            index += val;
        }
        result += s.substr(index, s.size() - prev);
        return result;
    }
};


// class Solution {
// public:
//     string addSpaces(string s, vector<int>& spaces) {
//         string result = "";
//         int index = 0;
//         for (int i = 0; i < s.size(); i++) {
//             if (index < spaces.size() && spaces[index] == i) {
//                 result += " ";
//                 index++;
//             }
//             result += s[i];
//         }
//         return result;
//     }
// };