// Link - https://leetcode.com/problems/circular-sentence/?envType=daily-question&envId=2024-11-02
// Circular Sentence


class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        if (n == 0) return true;

        char first = sentence[0], prev;
        for (int i = 1; i < n; i++) {
            if (sentence[i] == ' ') prev = sentence[i - 1];
            else if (sentence[i - 1] == ' ') {
                if (sentence[i] != prev) return false;
            }
        }

        if (first != sentence[n - 1]) return false;
        else return true;

    }
};