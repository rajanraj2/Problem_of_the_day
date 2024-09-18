// Link - https://leetcode.com/problems/largest-number/description/?envType=daily-question&envId=2024-09-18
// Largest Number


class Solution {
public:
    static bool customCompare(int a, int b) {
        string stra = to_string(a);
        string strb = to_string(b);
        return stra + strb > strb + stra;
    };

    string largestNumber(vector<int>& nums) {
        string result = "";
        sort(nums.begin(), nums.end(), customCompare);
        if (nums[0] == 0) return "0";
        for (int i = 0; i < nums.size(); i++) {
            result += to_string(nums[i]);
        }
        return result;
    }
};