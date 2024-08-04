// Link - https://leetcode.com/problems/count-number-of-teams/?envType=daily-question&envId=2024-07-29
// Count Number of Teams


class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;

        for (int i = 1; i < n - 1; i++) {
            int lessLeft = 0, greaterLeft = 0;
            int lessRight = 0, greaterRight = 0;

            for (int j = 0; j < i; j++) {
                if (rating[j] < rating[i]) lessLeft++;
                if (rating[j] > rating[i]) greaterLeft++;
            }

            for (int k = i; k < n; k++) {
                if (rating[k] < rating[i]) lessRight++;
                if (rating[k] > rating[i]) greaterRight++;
            }
            
            count += lessLeft * greaterRight + greaterLeft * lessRight;
        }

        return count;
    }
};