// Link - https://leetcode.com/problems/ugly-number-ii/description/?envType=daily-question&envId=2024-08-18
// Ugly Number II


class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        ugly[0] = 1;

        int i2 = 0, i3 = 0, i5 = 0;
        int next_multiple2 = 2;
        int next_multiple3 = 3;
        int next_multiple5 = 5;

        for (int i = 1; i < n; i++) {
            int next_ugly = min(next_multiple2, min(next_multiple3, next_multiple5));
            ugly[i] = next_ugly;

            if (next_ugly == next_multiple2) {
                i2++;
                next_multiple2 = ugly[i2] * 2;
            }
            if (next_ugly == next_multiple3) {
                i3++;
                next_multiple3 = ugly[i3] * 3;
            }
            if (next_ugly == next_multiple5) {
                i5++;
                next_multiple5 = ugly[i5] * 5;
            }
        }
        return ugly[n - 1];
    }
};