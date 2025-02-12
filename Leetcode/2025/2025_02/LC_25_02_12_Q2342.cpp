// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/?envType=daily-question&envId=2025-02-12
// 2342. Max Sum of a Pair With Equal Sum of Digits


class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int maxi = -1;
        vector<int> arr(82, 0);

        for (int it : nums) {
            int sum = 0, val = it;
            while (val) {
                int digit = val % 10;
                sum += digit;
                val /= 10;
            }
            if (arr[sum] > 0) maxi = max(maxi, arr[sum] + it);
            arr[sum] = max(arr[sum], it);
        }
        return maxi;
    }
};

// using heap

// class Solution {
// public:
//     int digitSum(int num) {
//         int sum = 0;
//         while (num) {
//             int digit = num % 10;
//             sum += digit;
//             num /= 10;
//         }
//         return sum;
//     }

//     int maximumSum(vector<int>& nums) {
//         vector<priority_queue<int, vector<int>, greater<int>>> arr(82);
//         int maxi = -1;
//         for (int it : nums) {
//             int sum = digitSum(it);
//             arr[sum].push(it);
//             if (arr[sum].size() > 2) arr[sum].pop();
//         }

//         for (auto it : arr) {
//             if (it.size() == 2) {
//                 int first = it.top();
//                 it.pop();
//                 int second = it.top();
//                 maxi = max(maxi, first + second);
//             }
//         }
//         return maxi;
//     }
// };


// using map and multiset

// class Solution {
// public:
//     int maximumSum(vector<int>& nums) {
//         unordered_map<int, multiset<int>> mpp;
//         int maxi = -1;

//         for (int i = 0; i < nums.size(); i++) {
//             int sum = 0, val = nums[i];
//             while (val) {
//                 int digit = val % 10;
//                 sum += digit;
//                 val /= 10;
//             }
//             mpp[sum].insert(nums[i]);
//         } 

//         for (auto it : mpp) {
//             auto st = it.second;
//             int s = st.size(), sum = 0;
//             if (s > 1) {
//                 auto it = st.rbegin();
//                 int firstMax = *it;
//                 it++;
//                 int secondMax = *it;
//                 maxi = max(maxi, firstMax + secondMax);
//             }
//         }
//         return maxi;
//     }
// };