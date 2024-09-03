// Link - https://leetcode.com/problems/sum-of-digits-of-string-after-convert/?envType=daily-question&envId=2024-09-03
// Sum of digits of string after convert


class Solution {
private:
    int add(int value) {
        int ans = 0;
        while (value) {
            ans += value % 10;
            value /= 10;
        }
        return ans;
    }

public:
    int getLucky(string s, int k) {
        int result = 0;
        for (auto it : s) {
            int val = it - 'a' + 1;
            if (val >= 10) {
                result += val / 10;
                val %= 10;
            }
            result += val; 
        }
        
        while (--k) {
            result = add(result);
        }
        return result;
    }
};