// Link - https://leetcode.com/problems/count-the-number-of-consistent-strings/?envType=daily-question&envId=2024-09-12
// Count the Number of Consistent Strings


class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> arr(26, 0);
        int result = 0;
        for (char it : allowed) {
            arr[it - 'a'] = 1;
        }

        for (auto it : words) {
            int count = 1;
            for (char ch : it) {
                if (arr[ch - 'a'] == 0) {
                    count = 0;
                    break;
                }
            }
            result += count;
        }

        return result;
    }
};


// Alternate method 

// class Solution {
// public:
//     int countConsistentStrings(string allowed, vector<string>& words) {
//         set<char> st(allowed.begin(), allowed.end());
//         int result = 0;
//         for (auto it : words) {
//             bool flag = true;
//             for (int i = 0; i < it.size(); i++) {
//                 if (st.find(it[i]) == st.end()) flag = false;
//             }
//             if (flag) result++;
//         }
//         return result;
//     }
// };