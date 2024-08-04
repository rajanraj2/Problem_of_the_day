// Link - https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/?envType=daily-question&envId=2024-06-24
// Minimum Number of K Consecutive Bit Flips


class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        queue<int> flipQueue; // to keep track of the flip indices
        int flips = 0; // count of the flips

        for (int i = 0; i < n; ++i) {
            // If the current element is out of the current flip window, pop it from the queue
            if (!flipQueue.empty() && flipQueue.front() <= i - k) {
                flipQueue.pop();
            }

            // Determine if the current bit needs to be flipped
            if (flipQueue.size() % 2 == nums[i]) {
                // If it's impossible to flip (if remaining length is less than k)
                if (i + k > n) {
                    return -1;
                }
                // Otherwise, flip the subarray starting from index i
                flipQueue.push(i);
                flips++;
            }
        }

        return flips;
    }
};


// Approach 1 : TLE

// class Solution {
// public:
//     int minKBitFlips(vector<int>& nums, int k) {
//         int n = nums.size();
//         int left = 0, right = k - 1;
//         int result = 0;
//         while (right < n) {
//             if (nums[left] == 0) {
//                 result++;
//                 for (int i = left; i <= right; i++) {
//                     nums[i] = 1 ^ nums[i];
//                 } 
//             }
//             left++;
//             right++;
//         }
        
//         for (int i = 0; i < n; i++) {
//             if (nums[i] == 0) {
//                 return -1;
//             }
//         }
//         return result;
//     }
// };