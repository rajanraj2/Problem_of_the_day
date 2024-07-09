// Link - https://leetcode.com/problems/average-waiting-time/?envType=daily-question&envId=2024-07-09
// Average waiting time


class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double totalwait = 0;
        vector<double> ct(n), tat(n);
        ct[0] = customers[0][0] + customers[0][1];
        for (int i = 1; i < n; i++) {
            if (customers[i][0] > ct[i - 1]) {
                ct[i] = customers[i][0] - ct[i - 1] + ct[i - 1] + customers[i][1];
                continue;
            }
            ct[i] = ct[i - 1] + customers[i][1];
        }
        for (int i = 0; i < n; i++) {
            tat[i] = ct[i] - customers[i][0];
            totalwait += tat[i];
        }
        return (double)totalwait/n;
    }
};