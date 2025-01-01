// https://leetcode.com/problems/maximum-score-after-splitting-a-string/?envType=daily-question&envId=2025-01-01
// maximum-score-after-splitting-a-string


// class Solution {
// public:
//     int maxScore(string s) {
//         int n = s.size();
//         vector<int> pre(n, 0), suf(n, 0);
//         pre[0] = (s[0] == '0');
//         suf[n - 1] = (s[n - 1] == '1');
//         int result = 0;
//         for (int i = 1; i < n; i++) {
//             pre[i] = pre[i - 1] + (s[i] == '0');
//             suf[n - i - 1] = suf[n - i] + (s[n - i - 1] == '1');
//         }
//         for (int i = 0; i < n - 1; i++) {
//             int val = pre[i] + suf[i + 1];
//             result = max(result, val);
//         }
//         return result;
//     }
// };


class Solution {
public:
    int maxScore(string s) {
        int one = 0, zero = 0;
        int best = INT_MIN;

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') one++;
            else zero++;
            best = max(best, zero - one); 
        }

        if (s.back() == '1') one++;
        return best + one;
    }
};