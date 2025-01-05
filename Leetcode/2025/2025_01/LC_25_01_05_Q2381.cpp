//  https://leetcode.com/problems/shifting-letters-ii/?envType=daily-question&envId=2025-01-05
// Shifting Letters II


class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> arr(n + 1, 0);
        for (auto it : shifts) {
            int start = it[0], end = it[1], dir = it[2];
            arr[start] += (dir == 1) ? 1 : -1;
            arr[end + 1] -= (dir == 1) ? 1 : -1;
        }

        for (int i = 1; i < n; i++) {
            arr[i] += arr[i - 1];
        }

        for (int i = 0; i < s.size(); i++) {
            int shift = (arr[i] % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }
        return s;
    }
};


// Brute Force

// class Solution {
// public:
//     string shiftingLetters(string s, vector<vector<int>>& shifts) {
//         for (auto it : shifts) {
//             for (int i = it[0]; i <= it[1]; i++) {
//                 if (it[2] == 1) {
//                     if (s[i] == 'z') s[i] = 'a';
//                     else s[i]++;
//                 }
//                 else {
//                     if (s[i] == 'a') s[i] = 'z';
//                     else s[i]--;
//                 }
//             }
//         }
//         return s;
//     }
// };