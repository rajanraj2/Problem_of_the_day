// Link - https://leetcode.com/problems/lemonade-change/description/?envType=daily-question&envId=2024-08-15
// Lemonade Change


class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (auto it : bills) {
            if (it == 5) {
                five++;
            }
            else if (it == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            }
            else {
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};