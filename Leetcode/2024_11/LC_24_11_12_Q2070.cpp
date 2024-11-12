// https://leetcode.com/problems/most-beautiful-item-for-each-query/?envType=daily-question&envId=2024-11-12
// Most Beautiful Item for Each Query


class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size(), m = queries.size();
        vector<int> result(m, 0);
        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        for (int i = 1; i < n; i++) items[i][1] = max(items[i][1], items[i - 1][1]);

        for (int i = 0; i < m; i++) {
            int left = 0, right = n - 1;
            int beauty = 0;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (items[mid][0] <= queries[i]) {
                    beauty = items[mid][1];
                    left = mid + 1;
                }
                else right = mid - 1;
            }
            result[i] = beauty;
        }
        return result;
    }
};