// Link - https://leetcode.com/problems/make-sum-divisible-by-p/description/?envType=daily-question&envId=2024-10-03
// Make Sum Divisible by P


class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long sum = 0;
        for (int it : nums) sum += it;

        int rem = sum % p;
        if (rem == 0) return 0;

        unordered_map<int, int> mpp;
        mpp[0] = -1;
        long psum = 0;
        int length = nums.size();

        for  (int i = 0; i < nums.size(); i++)  {
            psum += nums[i];
            int currentMod = psum % p;
            int targetMod = (currentMod - rem + p) % p;

            if (mpp.find(targetMod) != mpp.end()) {
                length = min(length, i - mpp[targetMod]);
            }

            mpp[currentMod] = i;
        }

        return length == nums.size() ? -1 : length;

    }
};