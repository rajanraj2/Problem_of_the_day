// https://leetcode.com/problems/first-completely-painted-row-or-column/?envType=daily-question&envId=2025-01-20
// 2661. First Completely Painted Row or Column


class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> mpp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mpp[mat[i][j]] = {i, j};
            }
        }
        vector<int> row(m, n), col(n, m);

        for (int i = 0; i < arr.size(); i++) {
            auto val = mpp[arr[i]];
            int r = val.first, c = val.second;
            row[r]--;
            col[c]--;
            if (row[r] == 0 || col[c] == 0) return i;
        }
        return -1;
    }
};