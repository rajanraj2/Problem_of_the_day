// https://leetcode.com/problems/find-missing-and-repeated-values/description/?envType=daily-question&envId=2025-03-06
// 2965. Find Missing and Repeated Values


class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n = grid.size();
            vector<int> result(2);
            vector<int> arr(n * n + 1, 0);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (arr[grid[i][j]] == 1) result[0] = grid[i][j];
                    arr[grid[i][j]]++;
                }
            }
    
            for (int i = 1; i <= n * n; i++) {
                if (arr[i] == 0) {
                    result[1] = i;
                    break;
                }
            }
            return result;
        }
    };