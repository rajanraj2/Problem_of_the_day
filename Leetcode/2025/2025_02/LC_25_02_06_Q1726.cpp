// https://leetcode.com/problems/tuple-with-same-product/description/?envType=daily-question&envId=2025-02-06
// 1726. Tuple with Same Product


class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int val = nums[i] * nums[j];
                mpp[val]++;
                count += mpp[val] - 1;
            }
        }
        return count * 8;
    }
};