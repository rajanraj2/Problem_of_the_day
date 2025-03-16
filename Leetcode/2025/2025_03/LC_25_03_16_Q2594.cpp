// https://leetcode.com/problems/minimum-time-to-repair-cars/?envType=daily-question&envId=2025-03-16
// 2594. Minimum Time to Repair Cars.


class Solution {
    public:
        long long repairCars(vector<int>& ranks, int cars) {
            long long left = 1, right = 1LL * ranks[0] * cars * cars;
            while (left <= right) {
                long long mid = left + (right - left) / 2, total = 0;
                for (auto it : ranks) total += (long long)sqrt(mid / it);
                if (total >= cars) right = mid - 1;
                else left = mid + 1;
            }
            return left;
        }
    };
    
    
    // class Solution {
    // public:
    //     long long repairCars(vector<int>& ranks, int cars) {
    //         vector<long long> freq(101, 0);
    //         int mini = INT_MAX, maxi = INT_MIN;
    //         for (int it : ranks) {
    //             mini = min(mini, it);
    //             maxi = max(maxi, it);
    //             freq[it]++;
    //         }
    
    //         long long left = 1, right = 1LL * mini * cars * cars;
    //         while (left <= right) {
    //             long long mid = left + (right - left) / 2, total = 0;
    //             for (int i = mini; i <= maxi; i++) total += freq[i] * (long long)sqrt(mid / i);
    //             if (total >= cars) right = mid - 1;
    //             else left = mid + 1;
    //         }
    //         return left;
    //     }
    // };