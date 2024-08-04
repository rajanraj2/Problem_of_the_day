// Link - https://leetcode.com/problems/three-consecutive-odds/description/?envType=daily-question&envId=2024-07-01
// Three Consecutive Odds


class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 2; i++) {
            if (arr[i + 2] % 2 == 1 && arr[i + 1] % 2 == 1 && arr[i] % 2 == 1) {
                return true;
            }
        }
        return false;
    }
};