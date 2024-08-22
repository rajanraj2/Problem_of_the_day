// Link - https://leetcode.com/problems/number-complement/description/?envType=daily-question&envId=2024-08-22
// Number Complement


class Solution {
public:
    int findComplement(int num) {
        int mask = 0;
        int temp = num;
        
        while (temp != 0) {
            mask = (mask << 1) | 1;
            temp >>= 1;
        }
        
        return num ^ mask;
    }
};


// class Solution {
// public:
//     int findComplement(int num) {
//         string bin = "";
//         while (num > 0) {
//             int bit = num % 2;
//             bin = to_string(1 - bit) + bin;
//             num /= 2;
//         }
//         int number = stoi(bin, nullptr, 2);
//         return number;
//     }
// };
