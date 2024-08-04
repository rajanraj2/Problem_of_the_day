// Link - https://leetcode.com/problems/second-minimum-time-to-reach-destination/?envType=daily-question&envId=2024-07-28
// Second Minimum Time to Reach Destination


class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, list<int>> mpp;
        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            mpp[u].push_back(v);
            mpp[v].push_back(u);   
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 1});

        vector<int> uniqueVisit(n + 1, 0);
        vector<int> dis(n + 1, -1);

        while (!q.empty()) {
            auto [t, node] = q.top();
            q.pop();

            if (dis[node] == t || uniqueVisit[node] >= 2) {
                continue;
            }

            uniqueVisit[node]++;
            dis[node] = t;

            if (node == n && uniqueVisit[node] == 2) {
                return dis[node];
            }

            if ((t / change) % 2 != 0) {
                t = (t / change + 1) * change;
            }

            for (int neigh : mpp[node]) {
                q.push({t + time, neigh});
            }
        }

        return -1;
    }
};