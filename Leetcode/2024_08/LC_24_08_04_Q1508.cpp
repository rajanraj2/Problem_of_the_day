// Link - https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/?envType=daily-question&envId=2024-08-04
// Range Sum of Sorted Subarray Sums


class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                arr.push_back(sum);
            }
        }

        sort(arr.begin(), arr.end());

        int result = 0;
        for (int i = left - 1; i < right; i++) {
            result = (result + arr[i]) % 1000000007;
            result += (arr[i] % 1000000007);
        }

        return result;
    }
};