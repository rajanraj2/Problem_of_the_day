// Link - https://leetcode.com/problems/maximum-distance-in-arrays/description/?envType=daily-question&envId=2024-08-16
// Maximum Distance in Arrays


class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = arrays[0][0];
        int maxi = arrays[0].back();
        int result = 0;

        for (int i = 1; i < arrays.size(); i++) {
            result = max(result, abs(arrays[i].back() - mini));
            result = max(result, abs(maxi - arrays[i][0]));

            mini = min(mini, arrays[i][0]);
            maxi = max(maxi, arrays[i].back());
        }

        return result;
    }
};