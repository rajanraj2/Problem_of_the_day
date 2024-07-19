// Link - https://leetcode.com/problems/lucky-numbers-in-a-matrix/?envType=daily-question&envId=2024-07-19
// Lucky Numbers in a Matrix


class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> lucky;
        for (int i = 0; i < matrix.size(); i++) {
            int mini = matrix[i][0];
            int minIndex = 0;

            for (int j = 1; j < matrix[i].size(); j++) {
                if (matrix[i][j] < mini) {
                    mini = matrix[i][j];
                    minIndex = j;
                }
            }

            bool isMax = true;
            for (int k = 0; k < matrix.size(); k++) {
                if (matrix[k][minIndex] > mini)
                    isMax = false;
            }

            if (isMax) {
                lucky.push_back(mini);
            }
        }
        return lucky;
    }
};


// class Solution {
// public:
//     vector<int> luckyNumbers(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<int> rmin(m);
//         vector<int> cmax(n);
//         vector<int> result;
//         for (int i = 0; i < m; i++) {
//             int mini = *min_element(matrix[i].begin(), matrix[i].end());
//             rmin[i] = mini;
//         }
//         for (int i = 0; i < n; i++) {
//             int maxi = INT_MIN;
//             for (int j = 0; j < m; j++) {
//                 maxi = max(maxi, matrix[j][i]);
//             }
//             cmax[i] = maxi;
//         }
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (matrix[i][j] == rmin[i] && matrix[i][j] == cmax[j]) {
//                     result.push_back(matrix[i][j]);
//                 }
//             }
//         }
//         return result;
//     }
// };
