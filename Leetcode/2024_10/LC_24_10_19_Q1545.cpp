// Link - https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/?envType=daily-question&envId=2024-10-19
// Find Kth Bit in Nth Binary String


class Solution {
public:
    string invert(string& s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') s[i] = '1';
            else s[i] = '0'; 
        }
        for (int i = 0; i < n / 2; i++) {
            swap(s[i], s[n - i - 1]);
        }
        return s;
    }

    char findKthBit(int n, int k) {
        string s = "0";
        string prev;
        for (int i = 1; i < n; i++) {
            prev = s;
            s = prev + "1" + invert(prev);
            if (s.size() >= k) break;
        }
        return s[k - 1];
    }
};