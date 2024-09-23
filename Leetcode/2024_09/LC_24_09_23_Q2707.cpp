// Link - https://leetcode.com/problems/extra-characters-in-a-string/?envType=daily-question&envId=2024-09-23
// Extra Characters in a String


class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> st(dictionary.begin(), dictionary.end());
        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;
            for (int j = 0; j < i; j++) {
                if (st.find(s.substr(j, i - j)) != st.end()) {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }

        return dp[n];
    }
};  