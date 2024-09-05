// Link - https://leetcode.com/problems/find-missing-observations/description/?envType=daily-question&envId=2024-09-05
// Find Missing Observations


class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int total = accumulate(rolls.begin(), rolls.end(), 0);
        int m = rolls.size();
         
        int total_sum = mean * (m + n);
        int missing_sum = total_sum - total;

        if (missing_sum < n || missing_sum > 6 * n) {
            return {};
        }

        vector<int> result(n, 1);
        missing_sum -= n;

        for (int i = 0; i < n && missing_sum > 0; i++) {
            int add_value = min(5, missing_sum);
            result[i] += add_value;
            missing_sum -= add_value;
        }

        return result;
    }
};


// class Solution {
// public:
//     vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
//         int total = accumulate(rolls.begin(), rolls.end(), 0);
//         int extra = mean * (rolls.size() + n) - total;
//         if (extra > n * 6 || extra < n) {
//             vector<int> result;
//             return result;
//         }
//         int rem = extra % n;
//         bool check = true;
//         if (rem != 0) check = false;
//         if (check) {
//             vector<int> result(n, extra / n);
//             return result;
//         }
//         else {
//             vector<int> result;
//             while (rem--) {
//                 result.push_back(extra / n + 1);
//             }
//             int s = result.size();
//             for (int i = 0; i < n - s; i++) {
//                 cout << i << endl;
//                 result.push_back(extra / n);
//             }
//             return result;
//         }
//     }
// };