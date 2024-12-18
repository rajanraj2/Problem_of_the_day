// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/?envType=daily-question&envId=2024-12-18
// Final Prices With a Special Discount in a Shop


// Monotonic stack

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> result = prices;
        stack<int> st;
        for (int i = 0; i < prices.size(); i++) {
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                result[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};


// Single Stack

// class Solution {
// public:
//     vector<int> finalPrices(vector<int>& prices) {
//         int n = prices.size(), top = 0;
//         vector<int> result = prices;
//         vector<int> st(500);
//         st[top] = n - 1;
        
//         for (int i = n - 2; i >= 0; i--) {
//             while (top >= 0 && prices[i] < prices[st[top]]) top--;
//             if (top >= 0) result[i] -= prices[st[top]];
//             st[++top] = i;
//         }
//         return result;
//     }
// };


// Two stacks

// class Solution {
// public:
//     vector<int> finalPrices(vector<int>& prices) {
//         int n = prices.size();
//         vector<int> result(n);
//         stack<int> st1, st2;
//         for (int i = n - 1; i >= 0; i--) {
//             st1 = st2;
//             while (!st1.empty() && st1.top() > prices[i]) st1.pop();
//             if (!st1.empty()) result[i] = prices[i] - st1.top();
//             else result[i] = prices[i];
//             st2.push(prices[i]);
//         }
//         return result;
//     }
// };


// Brute Force

// class Solution {
// public:
//     vector<int> finalPrices(vector<int>& prices) {
//         int n = prices.size();
//         vector<int> result(n);
//         for (int i = 0; i < n; i++) {
//             int index = -1;
//             for (int j = i + 1; j < n; j++) {
//                 if (prices[j] <= prices[i]) {
//                     index = j;
//                     break;
//                 }
//             }
//             if (index > 0 && index < n) result[i] = prices[i] - prices[index];
//             else result[i] = prices[i];
//         }
//         return result;
//     }
// };