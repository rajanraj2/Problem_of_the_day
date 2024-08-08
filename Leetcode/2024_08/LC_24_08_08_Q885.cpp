// Link - https://leetcode.com/problems/spiral-matrix-iii/?envType=daily-question&envId=2024-08-08
// Spiral Matrix III


class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        int row = rStart;
        int col = cStart;
        int step = 1;
        result.push_back({row, col});
        int total = rows * cols;

        while (result.size() < total) {
            // Move right
            for (int i = 0; i < step; i++) {
                col++;
                if (row >= 0 && row < rows && col >= 0 && col < cols) {
                    result.push_back({row, col});
                }
            }

            // Move down
            for (int i = 0; i < step; i++) {
                row++;
                if (row >= 0 && row < rows && col >= 0 && col < cols) {
                    result.push_back({row, col});
                }
            }
            step++;

            // Move left
            for (int i = 0; i < step; i++) {
                col--;
                if (row >= 0 && row < rows && col >= 0 && col < cols) {
                    result.push_back({row, col});
                }
            }

            // Move up
            for (int i = 0; i < step; i++) {
                row--;
                if (row >= 0 && row < rows && col >= 0 && col < cols) {
                    result.push_back({row, col});
                }
            }
            step++;
        }
        return result;
    }
};


// class Solution {
// public:
//     vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
//         vector<vector<int>> result;
//         int row = rStart;
//         int col = cStart;
//         int step = 1;
//         result.push_back({row, col});

//         while (result.size() < (rows * cols)) {
            
//             int ncol = col;
            
//             // Move right
//             while (abs(ncol - col) != step) {
//                 ncol++;
//                 if (row >= 0 && ncol >= 0 && row < rows && ncol < cols) {
//                     result.push_back({row, ncol});
//                 }
//             }
//             col = ncol;

//             // Move down
//             int nrow = row;
//             while (abs(nrow - row) != step) {
//                 nrow++;
//                 if (nrow >= 0 && col >= 0 && nrow < rows && col < cols) {
//                     result.push_back({nrow, col});
//                 }
//             }
//             row = nrow;
//             step++;

//             // Move left
//             ncol = col;
//             while (abs(ncol - col) != step) {
//                 ncol--;
//                 if (row >= 0 && ncol >= 0 && row < rows && ncol < cols) {
//                     result.push_back({row, ncol});
//                 }
//             }
//             col = ncol;

//             // Move up
//             nrow = row;
//             while (abs(nrow - row) != step) {
//                 nrow--;
//                 if (nrow >= 0 && col >= 0 && nrow < rows && col < cols) {
//                     result.push_back({nrow, col});
//                 }
//             }
//             row = nrow;
//             step++;
//         }

//         return result;
//     }
// };


