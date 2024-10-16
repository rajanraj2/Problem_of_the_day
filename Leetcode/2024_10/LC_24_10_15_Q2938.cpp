// Link - https://leetcode.com/problems/separate-black-and-white-balls/description/?envType=daily-question&envId=2024-10-15
// Separate black and white balls


class Solution {
public:
    long long minimumSteps(string s) {
        long long result = 0, count1 = 0;
        int n = s.size(), i = 0;

        while (i < n) {
            if (s[i] == '1') count1++;
            else result += count1;
            i++;
        }
        return result;
    }
};