// https://leetcode.com/problems/count-total-number-of-colored-cells/description/?envType=daily-question&envId=2025-03-05
// 2579. Count Total Number of Colored Cells


class Solution {
public:
    long long coloredCells(int n) {
        long long result = 1;
        if (n <= 1) return result;
        result += 1LL * (n - 1) * (2 * 4 + (n - 2) * 4) / 2;
        return result;
    }
};