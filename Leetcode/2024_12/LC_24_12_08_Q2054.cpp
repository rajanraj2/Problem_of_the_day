// https://leetcode.com/problems/two-best-non-overlapping-events/?envType=daily-question&envId=2024-12-08
// Two Best Non-Overlapping Events


class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        sort(events.begin(), events.end());
        int maxSum = 0, maxValue = 0;

        for (const auto& event : events) {
            int start = event[0], end = event[1], value = event[2];
            while (!pq.empty() && pq.top().first < start) {
                maxValue = max(maxValue, pq.top().second);
                pq.pop();
            }
            maxSum = max(maxSum, maxValue + value);
            pq.push({end, value});
        }
        
        return maxSum;
    }
};
