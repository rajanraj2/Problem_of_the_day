// Link - https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/?envType=daily-question&envId=2024-09-15
// Find the Longest Substring Containing Vowels in Even Counts


class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();
        int mask = 0, maxi = 0;
        unordered_map<int, int> mpp;
        mpp[0] = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') mask ^= (1 << 0);
            else if (s[i] == 'e') mask ^= (1 << 1);
            else if (s[i] == 'i') mask ^= (1 << 2);
            else if (s[i] == 'o') mask ^= (1 << 3);
            else if (s[i] == 'u') mask ^= (1 << 4);

            if (mpp.find(mask) != mpp.end()) {
                maxi = max(maxi, i - mpp[mask]);
            }
            else {
                mpp[mask] = i;
            }
        }

        return maxi;
    }
};