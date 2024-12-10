// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/?envType=daily-question&envId=2024-12-10
// Find Longest Special Substring That Occurs Thrice I


// Binary Search

class Solution {
private: 
    bool helper(string& s, int n , int x) {
        vector<int> count(26, 0);
        int p = 0;
        for (int i = 0; i < n; i++) {
            while (s[p] != s[i]) p++;
            if (i - p + 1 >= x) count[s[i] - 'a']++;
            if (count[s[i] - 'a'] > 2) return true;
        }
        return false;
    }

public:
    int maximumLength(string s) {
        int n = s.size();
        int l = 1, r = n;
        if (!helper(s, n, l)) return -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (helper(s, n, mid)) l = mid + 1;
            else r = mid - 1;
        }
        return r;
    }
};


// class Solution {
// public:
//     int maximumLength(string s) {
//         int n = s.size();
//         int result = -1;
//         map<string, int> mpp;
//         string prev;

//         for (int i = 0; i < n; i++) {
//             prev = "";
//             char ch = s[i];
//             for (int j = i; j < n; j++) {
//                 if (s[j] == ch) {
//                     prev += s[j];
//                     mpp[prev]++;
//                 }
//                 else break;
//             }
//         }

//         for (auto it : mpp) {
//             if (it.second >= 3) result = max(result, (int)it.first.size());
//         }
//         return result;
//     }
// };