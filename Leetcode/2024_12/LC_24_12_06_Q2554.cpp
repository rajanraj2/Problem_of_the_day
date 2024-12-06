// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/?envType=daily-question&envId=2024-12-06
// Maximum Number of Integers to Choose From a Range I

// Sweep

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(), banned.end());
        int count = 0, index = 0;
        int s = banned.size();

        for (int i = 1; i <= n; i++) {
            if (index < s && banned[index] == i) {
                while (index < s && banned[index] == i) index++;
            }
            else {
                maxSum -= i;
                if (maxSum < 0) break;
                count++;
            }
        }
        return count;
    }
};



// Binary search

// class Solution {
// private:
//     bool helper(vector<int>& arr, int target) {
//         int left = 0, right = arr.size() - 1;
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (arr[mid] == target) return true;
//             else if (arr[mid] < target) left = mid + 1;
//             else right = mid - 1;
//         }
//         return false;
//     }

// public:
//     int maxCount(vector<int>& banned, int n, int maxSum) {
//         sort(banned.begin(), banned.end());
//         int count = 0;
//         for (int i = 1; i <= n; i++) {
//             if (helper(banned, i)) continue;
//             maxSum -= i;
//             if (maxSum < 0) break;
//             count++;
//         }
//         return count;
//     }
// };



// Brute force

// class Solution {
// public:
//     int maxCount(vector<int>& banned, int n, int maxSum) {
//         int count = 0, sum = 0;
//         unordered_set<int> st(banned.begin(), banned.end());
//         for (int i = 1; i <= n; i++) {
//             if (st.count(i)) continue;
//             if (sum + i <= maxSum) {
//                 count++;
//                 sum += i;
//             }
//             else break;
//         }
//         return count;
//     }
// };
