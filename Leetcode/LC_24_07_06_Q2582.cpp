// Link - https://leetcode.com/problems/pass-the-pillow/description/?envType=daily-question&envId=2024-07-06
// Pass the Pillow


class Solution {
public:
    int passThePillow(int n, int time) {
        bool flag = true;
        int index = 0;
        for (int i = 0; i < time; i++) {
            if (index == n - 1) {
                flag = false;
            }
            else if (index == 0) {
                flag = true;
            }
            if (flag == true) {
                index++;
            }
            else {
                index--;
            }
        }
        return index + 1;
    }
};


// class Solution {
// public:
//     int passThePillow(int n, int time) {
//         int chunks = time / (n - 1);
//         int result;
//         if (chunks % 2 == 0) {
//             result = time % (n - 1) + 1;
//         }
//         else {
//             result = (n - time % (n - 1));
//         }
//         return result;
//     }
// };