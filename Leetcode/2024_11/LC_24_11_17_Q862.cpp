// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/?envType=daily-question&envId=2024-11-17
// Shortest Subarray with Sum at Least K


class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int result = INT_MAX;
        long long curr = 0;
        deque<pair<long long, int>> q;

        for (int i = 0; i < nums.size(); i++) {
            curr += nums[i];
            if (curr >= k) result = min(result, i + 1);
            
            while (!q.empty() && curr - q.front().first >= k) {
                auto [prefix, endIndex] = q.front();
                q.pop_front();
                result = min(result, i - endIndex);
            }

            while (!q.empty() && q.back().first > curr) q.pop_back();
            q.push_back({curr, i});
        }

        return result == INT_MAX ? -1 : result;
    }
};