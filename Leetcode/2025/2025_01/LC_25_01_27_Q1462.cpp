// https://leetcode.com/problems/course-schedule-iv/description/?envType=daily-question&envId=2025-01-27
// Course Schedule IV


class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bitset<100>> prereq(n);
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);

        for (auto &edge : prerequisites) {
            int a = edge[0], b = edge[1];
            adj[a].push_back(b);
            prereq[b].set(a);
            inDegree[b]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                prereq[v] |= prereq[u];
                if (--inDegree[v] == 0) q.push(v);
            }
        }

        vector<bool> result;
        result.reserve(queries.size());
        for (auto &it : queries) {
            int u = it[0], v = it[1];
            result.push_back(prereq[v][u]);
        }
        return result;
    }
};


// class Solution {
// public:
//     vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//         unordered_map<int, unordered_set<int>> reachable;
//         vector<bool> result;

//         for (auto &it : prerequisites) {
//             reachable[it[1]].insert(it[0]);
//         }

//         for (int i = 0; i < numCourses; i++) {
//             for (int j = 0; j < numCourses; j++) {
//                 if (reachable[j].count(i)) {
//                     reachable[j].insert(reachable[i].begin(), reachable[i].end());
//                 }
//             }
//         }

//         for (auto &it : queries) {
//             result.push_back(reachable[it[1]].count(it[0]) > 0);
//         }
//         return result;
//     }
// };