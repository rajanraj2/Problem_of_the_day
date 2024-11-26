// https://leetcode.com/problems/find-champion-ii/description/?envType=daily-question&envId=2024-11-26
// Find Champiton II


class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> incoming(n, 0);
        for (const auto& edge : edges) {
            incoming[edge[1]]++;
        }
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (incoming[i] == 0) result.push_back(i);
        }
        if (result.size() > 1) return -1;
        return result[0];
    }
};