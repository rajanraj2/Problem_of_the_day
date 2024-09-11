// Link - https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/?envType=daily-question&envId=2024-09-11
// Minimum Bit Flips to Convert Number


class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal;

        int count = 0;
        while (x > 0) {
            count += x & 1;
            x >>= 1;
        }

        return int(count);
    }
};


// Alternate method :

// class Solution {
// private:
//     string toBinary(int n) {
//         string s = "";
//         while (n > 0) {
//             s += to_string(n % 2);
//             n /= 2;
//         }
//         reverse(s.begin(), s.end());
//         return s;
//     }
// public:
//     int minBitFlips(int start, int goal) {
//         int count = 0;
//         string s1 = toBinary(start);
//         string s2 = toBinary(goal);
//         cout << s1 << " " << s2 << endl;

//         int size1 = s1.size(), size2 = s2.size(), diff = abs(size1 - size2); 
//         string temp(diff, '0');
//         if (size1 > size2) s2 = temp + s2;
//         else s1 = temp + s1;
//         cout << s1 << " " << s2 << endl;

//         for (int i = 0; i < s1.size(); i++) {
//             if (s1[i] != s2[i]) count++;
//         }

//         return count;
//     }
// };