// Link - https://leetcode.com/problems/build-a-matrix-with-conditions/?envType=daily-question&envId=2024-07-21
// Build a Matrix With Conditions


class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topologicalSort(k, rowConditions);
        vector<int> colOrder = topologicalSort(k, colConditions);
        
        if (rowOrder.empty() || colOrder.empty()) {
            return {};
        }
        
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        unordered_map<int, int> rowPosition, colPosition;
        
        for (int i = 0; i < k; ++i) {
            rowPosition[rowOrder[i]] = i;
            colPosition[colOrder[i]] = i;
        }
        
        for (int num = 1; num <= k; ++num) {
            int row = rowPosition[num];
            int col = colPosition[num];
            matrix[row][col] = num;
        }
        
        return matrix;
    }
    
private:
    vector<int> topologicalSort(int k, vector<vector<int>>& conditions) {
        vector<int> inDegree(k + 1, 0);
        unordered_map<int, vector<int>> graph;
        
        for (auto& condition : conditions) {
            int u = condition[0], v = condition[1];
            graph[u].push_back(v);
            ++inDegree[v];
        }
        
        queue<int> q;
        for (int i = 1; i <= k; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> order;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            
            for (int v : graph[u]) {
                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        if (order.size() != k) {
            return {};
        }
        
        return order;
    }
};