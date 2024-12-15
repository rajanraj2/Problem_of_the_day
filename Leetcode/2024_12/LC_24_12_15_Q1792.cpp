// https://leetcode.com/problems/maximum-average-pass-ratio/?envType=daily-question&envId=2024-12-15
// Maximum Average Pass Ratio


class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](const vector<int>& a) {
            return (double)(a[0] + 1) / (a[1] + 1) - (double)a[0] / a[1];
        };

        priority_queue<pair<double, vector<int>>> pq;
        for (auto& it : classes) pq.push({gain(it), it});

        while (extraStudents--) {
            auto [currentGain, cls] = pq.top();
            pq.pop();
            cls[0]++;
            cls[1]++;
            pq.push({gain(cls), cls});
        }

        double total = 0.0;
        while (!pq.empty()) {
            auto cls = pq.top().second;
            pq.pop();
            total += (double)cls[0] / cls[1];
        }

        return total / classes.size();
    }
};