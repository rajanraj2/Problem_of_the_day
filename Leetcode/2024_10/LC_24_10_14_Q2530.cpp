// Link - https://leetcode.com/problems/maximal-score-after-applying-k-operations/?envType=daily-question&envId=2024-10-14
// Maximal Score After Applying Operations


class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        long long score = 0;

        for (int i = 0; i < k; i++) {
            int top = maxHeap.top();
            maxHeap.pop();
            score += top;
            maxHeap.push(ceil(top / 3.0));
        }

        return score;
    }
};