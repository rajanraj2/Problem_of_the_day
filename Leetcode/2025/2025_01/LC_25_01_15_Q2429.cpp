// https://leetcode.com/problems/minimize-xor/?envType=daily-question&envId=2025-01-15
// Minimize XOR


class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n = num2, count = 0, ans = 0;
        while (n > 0) {
            n = n & (n - 1);
            count++;
        }

        for (int i = 31; i >= 0 && count > 0; i--) {
            if (num1 & (1 << i)) {
                ans |= (1 << i);
                count--;
            }
        }

        for (int i = 0; i < 32 && count > 0; i++) {
            if (!(ans & (1 << i))) {
                ans |= (1 << i);
                count--;
            }
        }

        return ans;
    }
};