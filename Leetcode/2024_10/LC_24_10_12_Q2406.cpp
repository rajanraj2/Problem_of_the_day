// Link - https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/?envType=daily-question&envId=2024-10-12
// Divide Intervals into Minimum Number of Groups


class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> start, ends;
        for (auto it : intervals) {
            start.push_back(it[0]);
            ends.push_back(it[1]);
        }

        sort(start.begin(), start.end());
        sort(ends.begin(), ends.end());

        int e = 0, result = 0;

        for (int it : start) {
            if (it > ends[e]) e++;
            else result++;
        }

        return result;
    }
};