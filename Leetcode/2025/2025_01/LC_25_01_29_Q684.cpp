// https://leetcode.com/problems/redundant-connection/description/?envType=daily-question&envId=2025-01-29'
// 684. Redundant Connection


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;

        auto isConnected = [&](int u, int v) {
            unordered_set<int> visited;
            stack<int> st;
            st.push(u);

            while (!st.empty()) {
                int node = st.top();
                st.pop();

                if (visited.count(node)) continue;
                visited.insert(node);
                
                if (node == v) return true;

                for (int it : graph[node]) {
                    st.push(it);
                }
            }
            return false;
        };

        for (const auto &edge : edges) {
            int u = edge[0], v = edge[1];

            if (graph.count(u) && graph.count(v) && isConnected(u, v)) return edge;
            graph[u].push_back(v);
            graph[v].push_back(u);
        } 
        return {};
    }
};