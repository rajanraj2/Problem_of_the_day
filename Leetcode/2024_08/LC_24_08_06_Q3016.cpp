// Link - https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/?envType=daily-question&envId=2024-08-06
// Minimum Number of Pushes to Type Word II


class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mpp;
        for (auto it : word) {
            mpp[it]++;
        }
        
        vector<int> freq;
        for (auto it : mpp) {
            freq.push_back(it.second);
        }
        sort(freq.rbegin(), freq.rend());

        int ans = 0; 
        for (int i = 0; i < freq.size(); i++) {
            int fac = i / 8 + 1;
            ans += freq[i] * fac;
        }

        return ans;
    }
};