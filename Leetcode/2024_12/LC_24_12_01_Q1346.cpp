// https://leetcode.com/problems/check-if-n-and-its-double-exist/description/?envType=daily-question&envId=2024-12-01
// Check If N and Its Double Exist


// using onordered_set

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;
        for (int it : arr) {
            if (st.count(it * 2) || ((it & 1) == 0 && st.count(it / 2))) return true;
            st.insert(it);
        }
        return false;
    }
};


// Using map

// class Solution {
// public:
//     bool checkIfExist(vector<int>& arr) {
//         map<int, int> mpp;
//         for (int i = 0; i < arr.size(); i++) mpp[arr[i]] = i + 1;
//         for (int i = 0; i < arr.size(); i++) {
//             if (mpp[2 * arr[i]] != i + 1 && mpp[2 * arr[i]] != 0) return true;
//         }
//         return false;
//     }
// };


// Using set

// class Solution {
// public:
//     bool checkIfExist(vector<int>& arr) {
//         set<int> st;
//         int count0 = 0;
//         for (int it : arr) {
//             if (it == 0) count0++;
//             st.insert(it);
//         }
//         if (count0 > 1) return true;
//         for (int it : arr) {
//             if (it != 0 && st.find(2 * it) != st.end()) return true;
//         }
//         return false;
//     }
// };

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();