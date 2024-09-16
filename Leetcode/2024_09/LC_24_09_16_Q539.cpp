// Link - https://leetcode.com/problems/minimum-time-difference/description/?envType=daily-question&envId=2024-09-16
// Minimum Time Difference


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int result = 0, mini = INT_MAX;
        int n = timePoints.size();
        vector<int> arr;
        for (string time : timePoints) {
            int hours = stoi(time.substr(0, 2));
            int mins = stoi(time.substr(3, 2));
            arr.push_back(hours * 60 + mins);
        }
        sort(arr.begin(), arr.end());

        for (int i = 1; i < arr.size(); i++) {
            int diff = arr[i] - arr[i - 1];
            mini = min(mini, diff);
        }

        int diff = 1440 - (arr.back() - arr[0]);
        mini = min(mini, diff);

        return mini;
    }
};