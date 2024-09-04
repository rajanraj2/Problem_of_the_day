// Link - https://leetcode.com/problems/walking-robot-simulation/description/?envType=daily-question&envId=2024-09-04
// Walking Robot Simulation


class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        set<pair<int, int>> st;
        for (auto it : obstacles) {
            st.insert({it[0], it[1]});
        }
        pair<int, int> start = {0, 0};
        int curr = 0;
        int result = 0;

        for (auto it : commands) {
            if (it == -1) {
                curr = (curr + 1) % 4;
            }
            else if (it == -2) {
                curr = (curr + 3) % 4;
            }
            else {
                for (int step = 0; step < it; step++) {
                    int newX = start.first + directions[curr].first;
                    int newY = start.second + directions[curr].second;

                    if (st.find({newX, newY}) != st.end()) break;

                    start.first = newX;
                    start.second = newY; 

                    result = max(result, start.first * start.first + start.second * start.second);
                }
            }
        }

        return result;
    }
};