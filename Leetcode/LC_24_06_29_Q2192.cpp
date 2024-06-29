// Link - https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/?envType=daily-question&envId=2024-06-29
// All Ancestors of a Node in a Directed Acyclic Graph


class Solution {
private :
    void dfs(vector<vector<int>>& graph, int parent, int cur,vector<vector<int>>& result, vector<bool>& visit) {
        visit[cur] = true;
        for (int it : graph[cur]) {
            if (!visit[it]) {
                result[it].push_back(parent);
                dfs(graph, parent, it, result, visit);
            }
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<vector<int>> result(n);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        for (int i = 0; i < n; i++) {
            vector<bool> visit(n, false);
            dfs(graph, i, i, result, visit);
        }
        for (int i = 0; i < n; i++) {
            sort(result[i].begin(), result[i].end());
        }
        return result;
    }
};