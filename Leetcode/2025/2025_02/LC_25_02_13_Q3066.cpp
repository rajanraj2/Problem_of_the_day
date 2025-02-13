// https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/?envType=daily-question&envId=2025-02-13
// 3066. Minimum Operations to Exceed Threshold Value II


class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long long, vector<long long>, greater<long long>> pq;
            int count = 0;
            for (auto it : nums) pq.push(it);
    
            while (!pq.empty() && pq.top() < k) {
                long long first = pq.top();
                pq.pop();
                long long second = pq.top();
                pq.pop();
                pq.push(2 * first + second);
                count++;
            } 
            return count;
        }
    };