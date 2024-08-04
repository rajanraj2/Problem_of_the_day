// Link - https://leetcode.com/problems/most-profit-assigning-work/?envType=daily-question&envId=2024-06-18
// Most Profit Assigning Work


class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        vector<pair<int, int>> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = {difficulty[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int maxProfit = 0, index = 0, result = 0;
        for (int ability : worker) {
            while ((index < n) && ability >= jobs[index].first) {
                maxProfit = max(maxProfit, jobs[index].second);
                index++;
            }
            result += maxProfit;
        }
        return result;
    }
};