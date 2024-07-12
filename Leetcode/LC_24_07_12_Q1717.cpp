// Link - https://leetcode.com/problems/maximum-score-from-removing-substrings/description/?envType=daily-question&envId=2024-07-12
// Maximum Score From Removing Substrings


class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score = 0;
        if (x < y) {
            swap(x, y);
            for (char &c : s) {
                if (c == 'a') c = 'b';
                else if (c == 'b') c = 'a';
            }
        }

        string stack;
        for (char c : s) {
            if (!stack.empty() && c == 'b' && stack.back() == 'a') {
                score += x;
                stack.pop_back();
            }
            else {
                stack.push_back(c);
            }
        }

        string remaining;
        swap(stack, remaining);

        for (char c : remaining) {
            if (!stack.empty() && c == 'a' && stack.back() == 'b') {
                score += y;
                stack.pop_back();
            }
            else {
                stack.push_back(c);
            }
        }

        return score;
    }
};


// class Solution {
// public:
//     int maximumGain(string s, int x, int y) {
//         int aCount = 0;
//         int bCount = 0;
//         int lesser = min(x, y);
//         int result = 0;

//         for (char c : s) {
//             if (c > 'b') {
//                 result += min(aCount, bCount) * lesser;
//                 aCount = 0;
//                 bCount = 0;
//             } else if (c == 'a') {
//                 if (x < y && bCount > 0) {
//                     bCount--;
//                     result += y;
//                 } else {
//                     aCount++;
//                 }
//             } else {
//                 if (x > y && aCount > 0) {
//                     aCount--;
//                     result += x;
//                 } else {
//                     bCount++;
//                 }
//             }
//         }

//         result += min(aCount, bCount) * lesser;
//         return result;
//     }
// };