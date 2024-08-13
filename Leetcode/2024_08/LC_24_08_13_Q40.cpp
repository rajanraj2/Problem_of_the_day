// Link - https://leetcode.com/problems/combination-sum-ii/?envType=daily-question&envId=2024-08-13
// Combination Sum II


class Solution {
private:
    void helper(vector<int>& candidates, int target, int sum, vector<int>& arr, vector<vector<int>>& result, int start) {
        if (sum == target) {
            result.push_back(arr);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            if (sum + candidates[i] > target) break;

            arr.push_back(candidates[i]);
            helper(candidates, target, sum + candidates[i], arr, result, i + 1);
            arr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> arr;
        helper(candidates, target, 0, arr, result, 0);
        return result;
    }
};

