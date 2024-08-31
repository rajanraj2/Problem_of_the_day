// Link - https://leetcode.com/problems/path-with-maximum-probability/?envType=daily-question&envId=2024-08-31
// Path with Maximum Probability


class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> maxPro(n, 0.0);
        maxPro[start_node] = 1.0;

        for (int i = 0; i < n - 1;  i++) {
            bool updated = false;
            for (int j = 0; j < edges.size(); j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                double prob = succProb[j];

                if (maxPro[u] * prob > maxPro[v]) {
                    maxPro[v] = maxPro[u] * prob;
                    updated = true;
                }
                if (maxPro[v] * prob > maxPro[u]) {
                    maxPro[u] =  maxPro[v] * prob;
                    updated = true;
                }
            }
            if (!updated) break;
        }

        return maxPro[end_node];
    }
};