// https://leetcode.com/problems/map-of-highest-peak/?envType=daily-question&envId=2025-01-22
// 1765. Map of Highest Peak


// class Solution {
// public:
//     vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
//         int m = isWater.size(), n = isWater[0].size();
//         vector<vector<int>> height(m, vector<int>(n, -1));
//         queue<pair<int, int>> q;
        
//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 if(isWater[i][j]) {
//                     height[i][j] = 0;
//                     q.push({i, j});
//                 }
//             }
//         }
//         int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
//         while(!q.empty()) {
//             auto [x, y] = q.front(); q.pop();
//             for(auto [dx, dy] : dirs) {
//                 int nx = x + dx, ny = y + dy;
//                 if(nx >= 0 && nx < m && ny >= 0 && ny < n && height[nx][ny] == -1) {
//                     height[nx][ny] = height[x][y] + 1;
//                     q.push({nx, ny});
//                 }
//             }
//         }
//         return height;
//     }
// };


class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int R = isWater.size();
        int C = isWater[0].size();
        vector<vector<int>> height(R, vector<int>(C, R + C));

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0; 
                } else {
                    if (i > 0) 
                        height[i][j] = min(height[i][j], height[i - 1][j] + 1); 
                    if (j > 0) 
                        height[i][j] = min(height[i][j], height[i][j - 1] + 1); 
                }
            }
        }

        for (int i = R - 1; i >= 0; i--) {
            for (int j = C - 1; j >= 0; j--) {
                if (i < R - 1) 
                    height[i][j] = min(height[i][j], height[i + 1][j] + 1);
                if (j < C - 1) 
                    height[i][j] = min(height[i][j], height[i][j + 1] + 1);
            }
        }

        return height;
    }
};