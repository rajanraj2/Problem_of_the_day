// Link - https://leetcode.com/problems/kth-distinct-string-in-an-array/description/?envType=daily-question&envId=2024-08-05
// Kth Distinct String in an Array


class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mpp;

        for (auto it : arr) {
            mpp[it]++;
        }

        int disCount = 0;
        for (const auto& it : arr) {
            if (mpp[it] == 1) {
                disCount++;
                if (disCount == k) {
                    return it;
                }
            }
        }

        return "";
    }
};