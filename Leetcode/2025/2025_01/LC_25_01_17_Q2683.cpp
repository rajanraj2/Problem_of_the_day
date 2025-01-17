// https://leetcode.com/problems/neighboring-bitwise-xor/description/?envType=daily-question&envId=2025-01-17
// Neighboring Bitwise XOR


class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int sum = accumulate(derived.begin(), derived.end(), 0);
        return (sum % 2 == 0);
    }
};


// class Solution {
// public:
//     bool doesValidArrayExist(vector<int>& derived) {
//         int x = 0;
//         for (int &it : derived) x ^= it;
//         return (x == 0);
//     }
// };


// class Solution {
// public:
//     bool doesValidArrayExist(vector<int>& derived) {
//         int prev = 0;
//         for (int i = 0; i < derived.size() - 1; i++) if (derived[i]) prev ^= 1;
//         if (derived.back() == (prev ^ 0)) return true;
//         return false;
//     }
// };