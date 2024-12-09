// https://leetcode.com/problems/special-array-ii/description/?envType=daily-question&envId=2024-12-09S
// Special Array II


// Binary search

// class Solution {
// public:
//     vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
//         int q = queries.size(), n = nums.size();
//         vector<bool> result(q, false); 
//         vector<int> arr;
//         bool prev = nums[0] % 2;
//         for (int i = 1; i < n; i++) {
//             if (prev == nums[i] % 2) arr.push_back(i);
//             prev = nums[i] % 2;
//         }

//         for (int i = 0; i < q; i++) {
//             int start = queries[i][0], end = queries[i][1];
//             int left = 0, right = arr.size() - 1;
//             bool flag = false;
//             while (left <= right) {
//                 int mid = left + (right - left) / 2;
//                 if (arr[mid] > end) right = mid - 1;
//                 else if (arr[mid] <= start) left = mid + 1;
//                 else {
//                     flag = true;
//                     break;
//                 }
//             }
//             if (!flag) result[i] = true;
//         }
//         return result;
//     }
// };


// Prefix

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int last = 0, n = nums.size(), q = queries.size();
        vector<int> arr(n); 
        vector<bool> result;
        result.reserve(q);
        arr[0] = 0;
        for (int i = 1; i < n; i++) {
            // last remains same till there is next same parity elements
            if (!((nums[i] & 1) ^ (nums[i - 1] & 1))) last = i;
            arr[i] = last;
        }

        for (auto& it : queries) {
            if (arr[it[0]] != arr[it[1]]) result.push_back(false);
            else result.push_back(true);
        }
        return result;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();