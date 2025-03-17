// https://leetcode.com/problems/divide-array-into-equal-pairs/?envType=daily-question&envId=2025-03-17
// 2206. Divide Array Into Equal Pairs


class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            bitset<501> parity;
            for (int &it : nums) parity.flip(it);
            return parity.none();
        }
    };
    
    
    // class Solution {
    // public:
    //     bool divideArray(vector<int>& nums) {
    //         vector<int> freq(501, 0);
    //         for (int &it : nums) freq[it]++;
    //         for (int &it : freq) {
    //             if (it % 2) return false;
    //         }
    //         return true;
    //     }
    // };