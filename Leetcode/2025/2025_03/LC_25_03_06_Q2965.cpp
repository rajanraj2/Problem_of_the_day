// https://leetcode.com/problems/find-missing-and-repeated-values/description/?envType=daily-question&envId=2025-03-06
// 2965. Find Missing and Repeated Values


// class Solution {
// public:
//     vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
//         int n = grid.size();
//         vector<int> result(2);
//         vector<int> arr(n * n + 1, 0);
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (arr[grid[i][j]] == 1) result[0] = grid[i][j];
//                 arr[grid[i][j]]++;
//             }
//         }

//         for (int i = 1; i <= n * n; i++) {
//             if (arr[i] == 0) {
//                 result[1] = i;
//                 break;
//             }
//         }
//         return result;
//     }
// };


// Math based approach also works (diff b/w actual and expected sum & actual and expected square sum)

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long sum = 0, sqrSum = 0;
        long long n = grid.size();
        long long total = n * n;

        // Calculate actual sum and squared sum from grid
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                sum += grid[row][col];
                sqrSum += static_cast<long long>(grid[row][col]) * grid[row][col];
            }
        }

        // Calculate differences from expected sums
        // Expected sum: n(n+1)/2, Expected square sum: n(n+1)(2n+1)/6
        long long sumDiff = sum - total * (total + 1) / 2;
        long long sqrDiff = sqrSum - total * (total + 1) * (2 * total + 1) / 6;

        // Using math: If x is repeated and y is missing
        // sumDiff = x - y
        // sqrDiff = x² - y²
        int repeat = (sqrDiff / sumDiff + sumDiff) / 2;
        int missing = (sqrDiff / sumDiff - sumDiff) / 2;

        return {repeat, missing};
    }
};
