// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/?envType=daily-question&envId=2025-01-06
// Minimum Number of Operations to Move All Balls to Each Box


class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> distances(n, 0);
        int prefixCount = 0;
        int prefixSum = 0;

        for (int i = 0; i < n; i++) {
            distances[i] = prefixCount * i - prefixSum;
            if (boxes[i] == '1') {
                prefixCount++;
                prefixSum += i;
            }
        }

        int suffixCount = 0;
        int suffixSum = 0;

        for (int i = n - 1; i >= 0; i--) {
            distances[i] += suffixSum - suffixCount * i;
            if (boxes[i] == '1') {
                suffixCount++;
                suffixSum += i;
            }
        }

        return distances;
    }
};


// class Solution {
// public:
//     vector<int> minOperations(string boxes) {
//         int n = boxes.size();
//         vector<int> result(n), arr;
//         for (int i = 0; i < n; i++) {
//             if (boxes[i] == '1') {
//                 arr.push_back(i);
//             }
//         }

//         for (int i = 0; i < n; i++) {
//             int more = 0, less = 0;
//             for (int j = 0; j < arr.size(); j++) {
//                 if (arr[j] >= i) {
//                     more += arr[j];
//                     less += i;
//                 }
//                 else {
//                     more += i;
//                     less += arr[j];
//                 }
//             }
//             result[i] = abs(more - less);
//         }
//         return result;
//     }
// };