// Link - https://leetcode.com/problems/rank-transform-of-an-array/?envType=daily-question&envId=2024-10-02
// Rank Transform of an Array


class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> arr2 = arr;
        sort(arr2.begin(), arr2.end());
        int n = arr.size(), rank = 1;
        if (n == 0) return arr;
        unordered_map<int, int> mpp;
        mpp[arr2[0]] = rank++;
 
        for (int i = 1; i < n; i++) {
            if (arr2[i] == arr2[i - 1]) mpp[arr2[i]] = --rank;
            else mpp[arr2[i]] = rank;
            rank++;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = mpp[arr[i]];
        }

        return arr;
    }
};