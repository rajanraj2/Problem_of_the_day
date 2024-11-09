// Link - https://leetcode.com/problems/minimum-array-end/?envType=daily-question&envId=2024-11-09
// Minimum Array End


class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x;
        long long remaining = n - 1;
        long long position = 1;
        
        while (remaining) {
            if (!(x & position)) {
                result |= (remaining & 1) * position;
                remaining >>= 1;
            }
            position <<= 1;
        }
        
        return result;
    }
};