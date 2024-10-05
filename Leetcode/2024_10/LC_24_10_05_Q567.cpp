// Link - https://leetcode.com/problems/permutation-in-string/?envType=daily-question&envId=2024-10-05
// Permuation in String


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        map<char, int> mpp1, mpp2;
        for (int i = 0; i < s1.size(); i++) {
            mpp1[s1[i]]++;
            mpp2[s2[i]]++;
        }

        for (int i = 0; i < s2.size() - s1.size(); i++) {
            if (mpp1 == mpp2) return true;
            mpp2[s2[i]]--;
            if (mpp2[s2[i]] == 0) mpp2.erase(s2[i]);
            mpp2[s2[i + s1.size()]]++;
        }

        return mpp1 == mpp2;
    }
};