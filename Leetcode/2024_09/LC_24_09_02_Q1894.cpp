// Link - https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/?envType=daily-question&envId=2024-09-02
// Find the Student that Will Replace the Chalk


class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total = accumulate(chalk.begin(), chalk.end(), 0LL);
        k = k % total;
        for (int i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) return i;
            k -= chalk[i];
        }
        return 0;
    }
};