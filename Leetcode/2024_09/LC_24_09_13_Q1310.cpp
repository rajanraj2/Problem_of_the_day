// Link - https://leetcode.com/problems/xor-queries-of-a-subarray/?envType=daily-question&envId=2024-09-13
// XOR Queries of a Subarray


class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = arr.size();
        vector<int> result;
        vector<int> pre(m);

        pre[0] = arr[0];
        for (int i = 1; i < m; i++) {
            pre[i] = pre[i - 1] ^ arr[i];
        }

        int ans;
        for (int i = 0; i < n; i++) {
            if (queries[i][0] == 0) ans = pre[queries[i][1]];
            else ans = pre[queries[i][1]]  ^ pre[queries[i][0] - 1];
            result.push_back(ans);
        }

        return result;
    }
};

// Alternate method 

// class Solution {
// public:
//     vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
//         int n = queries.size();
//         vector<int> result;

//         for (int i = 0; i < n; i++) {
//             int ans = 0;
//             for (int j = queries[i][0]; j <= queries[i][1]; j++) {
//                 ans ^= arr[j];
//             }
//             result.push_back(ans);
//         }

//         return result;
//     }
// };