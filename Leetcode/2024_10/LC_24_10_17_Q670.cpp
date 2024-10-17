// Link - https://leetcode.com/problems/maximum-swap/description/?envType=daily-question&envId=2024-10-17
// Maximum swap


class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        string str = s;
        sort(str.rbegin(), str.rend());
        int first, second;

        for (int i = 0; i < n; i++) {
            if (str[i] != s[i]) {
                first = i;
                second = str[i];
                break;
            }
        }

        for (int i = n; i > first; i--) {
            if (s[i] == second) {
                swap(s[i], s[first]);
                break;
            }
        }

        return stoi(s);
    }
};