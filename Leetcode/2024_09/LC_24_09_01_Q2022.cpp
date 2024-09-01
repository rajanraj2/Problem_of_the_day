// Link - https://leetcode.com/problems/convert-1d-array-into-2d-array/?envType=daily-question&envId=2024-09-01
// Convert 1D array into 2D array


class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result;
        if (m * n != original.size()) return result;
        int index = 0;

        for (int i = 0; i < m; i++) {
            vector<int> arr = {};
            for (int j = 0; j < n; j++) {
                if (index >= original.size()) break;
                arr.push_back(original[index++]);
            }
            result.push_back(arr);
        }

        return result;
    }
};