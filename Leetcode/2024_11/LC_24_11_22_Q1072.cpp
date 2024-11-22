// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/?envType=daily-question&envId=2024-11-22
// Flip Columns For Maximum Number of Equal Rows


class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mpp;
        for (const auto& row : matrix) {
            string pattern;
            if (row[0] == 0) for (int bit : row) pattern += to_string(bit);
            else for (int bit : row) pattern += to_string(bit ^ 1);
            mpp[pattern]++;
        }
        
        int result = 0;
        for (const auto& pair : mpp) result = max(result, pair.second);
        return result;
    }
};