// https://leetcode.com/problems/partition-labels/description/?envType=daily-question&envId=2025-03-30
// 763. Partition Labels


class Solution {
public:
    vector<int> partitionLabels(string s) {
        int start = 0;
        unordered_set<char> st;
        vector<int> arr(26, 0), result;
        for (auto &it : s) arr[it - 'a']++;

        for (int i = 0; i < s.size(); i++) {
            st.insert(s[i]);
            arr[s[i] - 'a']--;
            if (arr[s[i] - 'a'] == 0) st.erase(s[i]);
            if (st.empty()) {
                result.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};