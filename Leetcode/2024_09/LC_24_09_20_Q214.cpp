// Link - https://leetcode.com/problems/shortest-palindrome/description/?envType=daily-question&envId=2024-09-20
// Shortest Palindrome


class Solution {
private:
    int kmp(const string &txt, const string &patt) {
        string newString = patt + '#' + txt;
        vector<int> arr(newString.length(), 0);
        int i = 1, k = 0;
        while (i < newString.length()) {
            if (newString[i] == newString[k]) {
                k++;
                arr[i] = k;
                i++;
            }
            else {
                if (k > 0) {
                    k = arr[k - 1];
                }
                else {
                    arr[i] = 0;
                    i++;
                }
            }
        }

        return arr.back();
    }

public:
    string shortestPalindrome(string s) {
        int count = kmp(string(s.rbegin(), s.rend()), s);
        return string(s.rbegin(), s.rend()).substr(0, s.length() - count) + s;
    }
};