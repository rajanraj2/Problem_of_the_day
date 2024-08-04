// Link - https://leetcode.com/problems/maximum-total-importance-of-roads/?envType=daily-question&envId=2024-06-28
// Maximum total importance of roads


class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> count(n,0);
        long long result = 0;
        for (int i = 0; i < roads.size(); i++) {
            count[roads[i][0]]++;
            count[roads[i][1]]++;
        }
        sort(count.begin(), count.end());
        for (int i = 1; i <= n; i++) {
            result += (long long) i * count[i - 1];
        }
        return result;
    }
};