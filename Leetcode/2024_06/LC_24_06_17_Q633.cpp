// Link - https://leetcode.com/problems/sum-of-square-numbers/?envType=daily-question&envId=2024-06-17
// sum of square numbers


class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            long b = c - a * a;
            long sqrt_b = static_cast<long>(sqrt(b));
            if (sqrt_b * sqrt_b == b) {
                return true;
            }
        }
        return false;
    }
};