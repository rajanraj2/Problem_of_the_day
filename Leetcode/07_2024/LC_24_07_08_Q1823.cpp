// Link - https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/?envType=daily-question&envId=2024-07-08
// Find the Winner of the Circular Game -joshephus problem


class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0; 
        for (int i = 1; i <= n; i++) {
            winner = (winner + k) % i;
        }
        return winner + 1;
    }
};


// class Solution {
// private:
//     int helper(int n, int k, int start, vector<int>& arr) {
//         if (arr.size() == 1) return arr[0]; // base case
//         int next = (start + k - 1) % arr.size();
//         arr.erase(arr.begin() + next);
//         return helper(n, k, next, arr);
//     }

// public:
//     int findTheWinner(int n, int k) {
//         vector<int> arr(n);
//         for (int i = 0; i < n; i++) {
//             arr[i] = i + 1;
//         }
//         int result = helper(n, k, 0, arr);
//         return result;
//     }
// };

