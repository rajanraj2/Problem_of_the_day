// Link - https://leetcode.com/problems/height-checker/description/?envType=daily-question&envId=2024-06-10
// Height Checker


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int> expected(n);
        int count = 0;
        for (int i = 0; i < n; i++) {
            expected[i] = heights[i];
        }
        sort(expected.begin(), expected.end());
        for (int i = 0; i < n; i++) {
            if (expected[i] != heights[i]) {
                count++;
            }
        }
        return count;
    }
};