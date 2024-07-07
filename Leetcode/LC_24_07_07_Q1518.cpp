// Link - https://leetcode.com/problems/water-bottles/?envType=daily-question&envId=2024-07-07
// Water Bottles


class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrunk = 0;
        int emptyBottles = 0;

        while (numBottles > 0) {
            totalDrunk += numBottles;
            emptyBottles += numBottles;
            numBottles = emptyBottles / numExchange;
            emptyBottles = emptyBottles % numExchange;
        }
        return totalDrunk;
    }
};


// class Solution {
// private:
//     int helper(int numBottles,int numExchange) {
//         if (numBottles < numExchange) return 0;
//         int fullBottles = numBottles / numExchange;
//         int rem = numBottles % numExchange;
//         return fullBottles + helper(fullBottles + rem, numExchange);
//     }

// public:
//     int numWaterBottles(int numBottles, int numExchange) {
//         int result = numBottles;
//         result += helper(numBottles, numExchange);
//         return result;  
//     }
// };


