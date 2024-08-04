// Link - https://leetcode.com/problems/grumpy-bookstore-owner/description/?envType=daily-question&envId=2024-06-21
// Grumpy Bookstore Owner


class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int satis = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) satis += customers[i];
        }

        int maxadd = 0, currentadd = 0;

        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                currentadd += customers[i];
            }
        }
        maxadd = currentadd;

        for (int i = minutes; i < n; i++)  {
            if (grumpy[i] == 1) {
                currentadd += customers[i];
            }
            if (grumpy[i - minutes] == 1) {
                currentadd -= customers[i - minutes];
            }
            maxadd = max(maxadd, currentadd);
        }
        return satis + maxadd;  
    }
};