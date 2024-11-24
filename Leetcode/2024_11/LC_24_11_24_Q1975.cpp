// https://leetcode.com/problems/maximum-matrix-sum/description/?envType=daily-question&envId=2024-11-24
// Maximum Matrix Sum


class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
         long long result = 0;
         int minValue = INT_MAX, count = 0;
         int n = matrix.size(), m = matrix[0].size();

         for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] < 0) count++;
                int absValue = abs(matrix[i][j]);
                minValue = min(minValue, absValue);
                result += absValue;
            }
         }

         if (count % 2 == 0) return result;
         return result - 2 * minValue;
    }
};