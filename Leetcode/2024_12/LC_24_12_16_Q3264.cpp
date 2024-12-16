// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/description/?envType=daily-question&envId=2024-12-16
// Final Array State After K Multiplication Operations I


// Priority Queue

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++) pq.push({nums[i], i});

        while (k--) {
            auto it = pq.top();
            pq.pop();
            pq.push({it.first * multiplier, it.second});
        }

        vector<int> result(n);
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            result[it.second] = it.first;
        }
        return result;
    }
};


// Brute Force

// class Solution {
// public:
//     vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
//         for (int i = 0; i < k; i++) {
//             int mini = 0;
//             for (int i = 1; i < nums.size(); i++) {
//                 if (nums[i] < nums[mini]) {
//                     mini = i;
//                 }
//             }
//             nums[mini] *= multiplier;
//         }
//         return nums;
//     }
// };