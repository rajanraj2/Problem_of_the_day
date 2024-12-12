// https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/?envType=daily-question&envId=2024-12-12
// Take Gifts from the Richest Pile


// priority queue

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long result = 0;
        priority_queue<int> pq(gifts.begin(), gifts.end());

        for (int i = 0; i < k; i++) {
            int val = pq.top();
            pq.pop();
            pq.push(sqrt(val));
        }

        while (!pq.empty()) {
            result += pq.top();
            pq.pop();
        }
        return result;
    }
};


// Brute Force

// class Solution {
// public:
//     long long pickGifts(vector<int>& gifts, int k) {
//         sort(gifts.rbegin(), gifts.rend());
//         for (int i = 0; i < k; i++) {
//             gifts[0] = sqrt(gifts[0]);
//             sort(gifts.rbegin(), gifts.rend());
//         }

//         long long result = 0;
//         for (int it : gifts) result += it;
//         return result;
//     }
// };