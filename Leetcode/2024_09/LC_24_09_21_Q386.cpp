// Link - https://leetcode.com/problems/lexicographical-numbers/?envType=daily-question&envId=2024-09-21
// Lexicographical Numbers


class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> arr;
        int curr = 1;

        while (arr.size() < n) {
            arr.push_back(curr);
            
            if (curr * 10 <= n) curr *= 10;
            else {
                while (curr % 10 == 9 || curr >= n) curr /= 10;
                curr++;
            } 
        }
        return arr;
    }
};


// Alternate method 

// bool customComparator(int a, int b) {
//     string stra = to_string(a);
//     string strb = to_string(b);
//     int i = 0;

//     while (i < stra.size() && i < strb.size()) {
//         if (stra[i] < strb[i]) return true;
//         else if (stra[i] > strb[i]) return false;
//         else i++;
//     }

//     if (i == stra.size()) return true;
//     else return false;
// }

// class Solution {
// public:
//     vector<int> lexicalOrder(int n) {
//         vector<int> arr(n);
//         for (int i = 0; i < n; i++) arr[i] = i + 1;

//         sort(arr.begin(), arr.end(), customComparator);
//         return arr;
//     }
// };