// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/?envType=daily-question&envId=2025-03-08
// 2379. Minimum Recolors to Get K Consecutive Black Blocks


// n

class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int n = blocks.size(), white = 0, result = INT_MAX;
            for (int  i = 0; i < k; i++) {
                if (blocks[i] == 'W') white++;
            }
            result = min(result, white); 
            for (int i = k; i < n; i++) {
                if (blocks[i - k] == 'W') white--;
                if (blocks[i] == 'W') white++;
                result = min(result, white);
            }
            return result;
        }
    };
    
    // n^2
    
    // class Solution {
    // public:
    //     int minimumRecolors(string blocks, int k) {
    //         int n = blocks.size(), result = INT_MAX;
    //         for (int i = 0; i < n - k + 1; i++) {
    //             int cost = 0;
    //             for (int j = i; j < i + k; j++) {
    //                 if (blocks[j] == 'W') cost++;
    //             }
    //             result = min(result, cost);
    //         }
    //         return result;
    //     }
    // };