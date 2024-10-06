// Link - https://leetcode.com/problems/sentence-similarity-iii/?envType=daily-question&envId=2024-10-06
// Sentence Similarity III


class Solution {
public:
    vector<string> toVec(string& s){
        stringstream ss(s);
        vector<string> ans;
        string w;
        while (ss>>w)
            ans.push_back(w);
        ss.clear();
        return ans;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1 = toVec(sentence1), s2 = toVec(sentence2);
        int m = s1.size(), n = s2.size();

        if (n < m) {
            swap(s1, s2);
            swap(n, m);
        }
        int l = 0, r1 = m - 1, r2 = n - 1;

        while (l < m && s1[l] == s2[l]) l++;

        while (r1 >= 0 && s1[r1] == s2[r2]) {
            r1--;
            r2--;
        }
        
        return r1 < l;
    }
};