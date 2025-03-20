// https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/?envType=daily-question&envId=2025-03-20
// 3108. Minimum Cost Walk in Weighted Graph


// 1 - make the adjacency list for the graph
// 2 - the answer for a given pair will be bitwise and of all the elements in the component if both start and 
// end belong to same component
// 3 - ohterwise -1
// 4 - use dfs to travel in the graph
// 5 - all the elements which belong to the same component will be given same component number
// 6 - map will store bitwise and of all the the edges in a given component
// 7 - if start and end belong to same component number we can fetch the result from the map for that component
// 8 - otherwise result for that pair would be -1


class Solution {
private:
    void dfs(unordered_map<int, vector<pair<int, int>>> &adj, unordered_map<int, pair<int , int>> &vis, 
    unordered_map<int, int> &components, int component, int start, int &value) {
        vis[start].first = 1;
        vis[start].second = component;
        for (auto it : adj[start]) {
            if (!vis[it.first].first) {
                value &= it.second;
                dfs(adj, vis, components, component, it.first, value);
            }
            else if (vis[it.first].second == component) {
                value &= it.second;
            }
        }
        components[component] = value;
    }

public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        unordered_map<int, vector<pair<int, int>>> adj;
        unordered_map<int, pair<int , int>> vis;
        unordered_map<int, int> components;
        vector<int> result; 
        result.reserve(query.size());
        int component = 1;
        adj.reserve(n);

        for (auto it : edges) {
            bool flag = true, flag2 = true;
            for (int i = 0; i < adj[it[0]].size(); i++) {
                int prev = adj[it[0]][i].second;
                if (adj[it[0]][i].first == it[1]) {
                    adj[it[0]][i] = {it[1], prev & it[2]};
                    flag = false;
                    break;
                }
            }

            for (int i = 0; i < adj[it[1]].size(); i++) {
                int prev = adj[it[1]][i].second;
                if (adj[it[1]][i].first == it[0]) {
                    adj[it[1]][i] = {it[0], prev & it[2]};
                    flag2 = false;
                    break;
                }
            }
            
            if (flag) adj[it[0]].push_back({it[1], it[2]});
            if (flag2) adj[it[1]].push_back({it[0], it[2]});
            vis[it[0]] = {0, 0};
            vis[it[1]] = {0, 0};
        }

        for (auto it : vis) {
            if (it.second.first == 1) continue;
            component++;
            int value = ~0;
            dfs(adj, vis, components, component, it.first, value);
        }

        for (auto it : query) {
            if (vis.find(it[0]) == vis.end() || vis.find(it[1]) == vis.end()) result.push_back(-1);
            else if (vis[it[0]].second != vis[it[1]].second) result.push_back(-1);
            else result.push_back(components[vis[it[0]].second]);
        }
        return result;
    }
};