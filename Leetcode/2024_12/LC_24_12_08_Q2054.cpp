// https://leetcode.com/problems/two-best-non-overlapping-events/?envType=daily-question&envId=2024-12-08
// Two Best Non-Overlapping Events


// Greedy approach

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<vector<int>> arr;
        for (auto& it : events) {
            arr.push_back({it[0], 1, it[2]});
            arr.push_back({it[1] + 1, 0, it[2]});
        }

        int result = 0, maxValue = 0;
        sort(arr.begin(), arr.end());
        for (auto& it : arr) {
            if (it[1]) result = max(result, it[2] + maxValue);
            else maxValue = max(maxValue, it[2]);
        } 
        return result;
    }
};


// Heap

// class Solution {
// public:
//     int maxTwoEvents(vector<vector<int>>& events) {
//         int n = events.size();
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         sort(events.begin(), events.end());
//         int maxSum = 0, maxValue = 0;

//         for (const auto& event : events) {
//             int start = event[0], end = event[1], value = event[2];
//             while (!pq.empty() && pq.top().first < start) {
//                 maxValue = max(maxValue, pq.top().second);
//                 pq.pop();
//             }
//             maxSum = max(maxSum, maxValue + value);
//             pq.push({end, value});
//         }

//         return maxSum;
//     }
// };
