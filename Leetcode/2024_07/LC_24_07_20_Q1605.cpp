// Link - https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/?envType=daily-question&envId=2024-07-20
// Find Valid Matrix Given Row and Column Sums


class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> mat(n, vector<int>(m, 0));

        int i = 0, j = 0;
        while (i < n && j < m) {
            int val = min(rowSum[i], colSum[j]);
            mat[i][j] = val;
            rowSum[i] -= val;
            colSum[j] -= val;
            if (rowSum[i] == 0) ++i;
            if (colSum[j] == 0) ++j;
        }
        return mat;
    }
};


// class Solution {
// public:
//     vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
//         int n = rowSum.size();
//         int m = colSum.size();
//         vector<vector<int>> mat(n,vector<int>(m,0));
//         for(int i = 0; i < n; i++ ){
//             for(int j = 0; j < m; j++){
//                 mat[i][j] = min(rowSum[i],colSum[j]);
//                 rowSum[i] -=mat[i][j];
//                 colSum[j]-=mat[i][j];
//             }
//         }
//         return mat;
//     }
// };