// Link - https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/?envType=daily-question&envId=2024-06-13
//  Minimum Number of Moves to Seat Everyone


class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size();
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int count  = 0;
        for (int i = 0; i < n; i++) {
            int diff = seats[i]  - students[i]; 
            if (diff < 0) diff = (diff * (-1));
            count += diff;
        }
        return count;
    }
};
