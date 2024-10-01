// Link - https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/?envType=daily-question&envId=2024-10-01
// Check if Array Pairs Are Divisible by k


class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int, int> mpp;

        for (int it : arr) {
            int rem = it % k;
            if (rem < 0) rem += k;
            mpp[rem]++;
        }
        
        for (auto it : mpp) {
            int rem = it.first;
            if (rem == 0) {
                if (mpp[rem] % 2 != 0) return false;
            }
            else if (mpp[rem] != mpp[k - rem]) return false;
        }

        return true;
    }
};