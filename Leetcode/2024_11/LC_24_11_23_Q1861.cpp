// https://leetcode.com/problems/rotating-the-box/?envType=daily-question&envId=2024-11-23
// Rotating the Box


class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        vector<vector<char>> result(m, vector<char> (n));

        for (int i = 0; i < n; i++) {
            int pos = m - 1;
            for (int j = m - 1; j >= 0; j--) {
                if (box[i][j] == '#') swap(box[i][j], box[i][pos--]);
                else if (box[i][j] == '*') pos = j - 1;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[j][n - i - 1] = box[i][j];
            }
        }
        return result;
    }
};


// class Solution {
// public:
//     vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
//         int m = box.size(), n = box[0].size();
//         vector<vector<int>> mat(m, vector<int> (n));
//         vector<vector<char>> grid(n, vector<char> (m));
//         for (int i = 0; i < m; i++) {
//             int count = 0;
//             for (int j = 0; j < n; j++) {
//                 if (box[i][j] == '#') {
//                     count++;
//                     mat[i][j] = count;
//                 }
//                 else if (box[i][j] == '*') {
//                     mat[i][j] = -1;
//                     count = 0;
//                 }
//                 else if (box[i][j] == '.') {
//                     mat[i][j] = count;
//                 }
//             }
//         }

//         for (int j = m - 1; j >= 0; j--) {
//             for (int i = n - 1; i >= 0; i--) {

//                 if (mat[m - j - 1][i] == -1) grid[i][j] = '*';
//                 else if (mat[m - j - 1][i] > 0) {

//                     cout << mat[m - j - 1][i] << " " << i << " " << j << endl;
//                     grid[i][j] = '#';
//                     if (i - 1 >= 0 && mat[m - j - 1][i - 1] >= mat[m - j - 1][i]) {
//                         if (mat[m - j - 1][i] == 0 && mat[m - j - 1][i - 1] != -1) {
//                             mat[m - j - 1][i - 1] = 0;
//                         }
//                         else mat[m - j - 1][i - 1] = mat[m - j - 1][i] - 1;
//                     }
//                 }
//                 else {
//                     if (i - 1 >= 0 && mat[m - j - 1][i - 1] != -1) mat[m - j - 1][i - 1] = 0;
//                     grid[i][j] = '.';
//                 }
//             }
//             cout << endl;
//         }

//         return grid;

//     }
// };