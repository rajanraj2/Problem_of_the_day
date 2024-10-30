// Link - https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/?envType=daily-question&envId=2024-10-30
// Minimum Number of Removals to Make Mountain Array


class Solution {
private:
    vector<int> lisLength(vector<int>& arr) {
        vector<int> lis = {arr[0]};
        vector<int> lisLen(arr.size(), 1);

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > lis.back()) lis.push_back(arr[i]);
            else {
                int index = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
                lis[index] = arr[i];
            }

            lisLen[i] = lis.size();
        }
        return lisLen;
    }

public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis = lisLength(nums);

        reverse(nums.begin(), nums.end());
        vector<int> lds = lisLength(nums);
        reverse(lds.begin(), lds.end());

        int result = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (lis[i] > 1 && lds[i] > 1) result = min(result, n + 1 - lis[i] - lds[i]);
        }

        return result;
    }
};