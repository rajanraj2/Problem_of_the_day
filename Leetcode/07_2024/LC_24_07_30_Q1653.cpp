// Link - https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/?envType=daily-question&envId=2024-07-30
// Minimum Deletions to Make String Balanced


class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0;
        int countB = 0;
        for (auto c : s) {
            if (c == 'b') {
                countB++;
            } else {
                ans = min(ans + 1, countB);
            }
        }
        return ans;
    }
};