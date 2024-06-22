// Link - https://leetcode.com/problems/count-number-of-nice-subarrays/description/
// Count Number of Nice Subarrays


class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int odd = 0, result = 0; 
        unordered_map<int,int> mp;
        mp[0] = 1;

        for (int num : nums) {
            if (num % 2 == 1) {
                odd++;
            }
            if (mp.find(odd - k) != mp.end()) {
                result += mp[odd - k];
            }
            mp[odd]++;
        }
        return result;
    }
};