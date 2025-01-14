// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/?envType=daily-question&envId=2025-01-14
// Find the Prefix Common Array of Two Arrays


class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int count = 0, n = A.size();
        vector<int> arr(n, 0), result(n);
        
        for (int i = 0; i < n; i++) {
            arr[A[i] - 1]++;
            if (arr[A[i] - 1] == 2) count++;
            arr[B[i] - 1]++;
            if (arr[B[i] - 1] == 2) count++;
            result[i] = count;
        }
        return result;
    }
};