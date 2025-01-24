// https://leetcode.com/problems/find-eventual-safe-states/?envType=daily-question&envId=2025-01-24
// 802. Find Eventual Safe States


class Solution {
public:
    void reverseGraph(vector<vector<int>> &graph, vector<int> &degreein, vector<vector<int>> &rGraph) {
        int n = graph.size();
        degreein = vector<int>(n, 0);
        rGraph.resize(n, vector<int> (0));

        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                rGraph[v].push_back(u);
                degreein[u]++;
            }
        }
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> degreein;
        vector<vector<int>> rGraph;
        vector<int> ans;
        int n = graph.size();

        reverseGraph(graph, degreein, rGraph);
        
        queue<int> q;
        for (int i = 0; i < n; i++) if (degreein[i] == 0) q.push(i);

        while (q.size()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (int v : rGraph[u]) {
                degreein[v]--;
                if (degreein[v] == 0) q.push(v);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};