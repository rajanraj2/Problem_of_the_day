// https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/?envType=daily-question&envId=2024-12-13
// Find Score of an Array After Marking All Elements


// Priority Queue

class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++) pq.push({nums[i], i});
        vector<int> marked(n, 0);

        for (int i = 0; i < n; i++) {
            auto it = pq.top();
            pq.pop();
            int value = it.first;
            int index = it.second;
            if (marked[index]) continue;
            score += value;
            marked[index] = 1;
            if (index > 0) marked[index - 1] = 1;
            if (index < n - 1) marked[index + 1] = 1;
        }
        return score;
    }
};


// Brute Force - TLE

// class Solution {
// public:
//     long long findScore(vector<int>& nums) {
//         long long score = 0;
//         int n = nums.size(), count = 0;
//         vector<int> marked(n, 0);

//         while (true) {
//             int mini = INT_MAX, index;
//             for (int i = 0; i < n; i++) {
//                 if (marked[i] == 1) continue;
//                 if (mini > nums[i]) {
//                     index = i;
//                     mini = nums[i];
//                 }
//             }
//             if (index >= 1 && marked[index - 1] != 1) {
//                 marked[index - 1] = 1;
//                 count++;
//             }
//             if (index <= n - 2 && marked[index + 1] != 1) {
//                 marked[index + 1] = 1;
//                 count++;
//             }
//             score += nums[index];
//             count++;
//             marked[index] = 1;
//             if (count >= n) break;
//         }
//         return score;
//     }
// };