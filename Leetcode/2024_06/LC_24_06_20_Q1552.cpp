// Link - https://leetcode.com/problems/magnetic-force-between-two-balls/description/?envType=daily-question&envId=2024-06-20
// Magnetic Force Between Two Balls


class Solution {
public:
    bool isPossible(vector<int> arr, int m, int min_dist) {
        int ball = 1, last_pos = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - last_pos >= min_dist) {
                ball++;
                last_pos = arr[i];
            }
            if (ball >= m) return true;
        }
        return false;        
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size(), low = 1, high = position[n - 1] - position[0];
        int result = 0;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (isPossible(position, m, mid)) {
                result = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return result;
    }
};