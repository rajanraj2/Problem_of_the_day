// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/?envType=daily-question&envId=2025-03-04
// 1780. Check if Number is a Sum of Powers of Three


class Solution {
    public:
        bool checkPowersOfThree(int n) {
            while (n) {
                if (n % 3 == 2) return false;
                n /= 3;
            }
            return true;
        }
    };
    
    
    // class Solution {
    // public:
    //     bool checkPowersOfThree(int n) {
    //         vector<int> arr;
    //         int val = 1, k = n;
    //         while (arr.size() == 0 || arr.back() <= 1e7) {
    //             arr.push_back(val);
    //             val *= 3;
    //         }
    
    //         for (int i = arr.size() - 1; i >= 0; i--) {
    //             if (arr[i] <= k) k -= arr[i];
    //             if (k == 0) return true;
    //             if (k < 0) return false;
    //         }
    //         return false;
    //     }
    // };