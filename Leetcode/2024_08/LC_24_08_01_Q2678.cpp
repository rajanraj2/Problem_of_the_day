// Link - https://leetcode.com/problems/number-of-senior-citizens/?envType=daily-question&envId=2024-08-01
// /Number of Senior Citizens


class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for (int i = 0; i < details.size(); i++) {
            int age = 0;
            age += (details[i][11] - '0') * 10;
            age += details[i][12] - '0';
            cout << age << endl;
            if (age > 60) {
                count++;
            }
        }
        return count;
    }
};