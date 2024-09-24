// Link - https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/?envType=daily-question&envId=2024-09-24
// Find the Length of the Longest Common Prefix


class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> prefixMap;

        for (int num : arr1) {
            string strNum = to_string(num);
            string prefix = "";
            for (char ch : strNum) {
                prefix += ch;
                prefixMap[prefix]++;
            }
        }
        
        int maxLength = 0;
        
        for (int num : arr2) {
            string strNum = to_string(num);
            string prefix = "";
            for (char ch : strNum) {
                prefix += ch;
                if (prefixMap.find(prefix) != prefixMap.end()) {
                    maxLength = max(maxLength, static_cast<int>(prefix.length()));
                }
            }
        }
        
        return maxLength;
    }
};