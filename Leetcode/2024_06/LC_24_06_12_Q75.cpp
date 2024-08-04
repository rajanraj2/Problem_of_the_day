// Link - https://leetcode.com/problems/sort-colors/submissions/1285656998/?envType=daily-question&envId=2024-06-12
// 75. Sort Colors


// Alternate method 1 : nested loop
// Alternate method 2 : count var for 0,1 & 2;
// Alternate method 3 : Dutch national flag algorithm

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) mid ++;
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};


// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int n = nums.size();
//         int count0 = 0, count1 = 0, count2 = 0;

//         for (int i = 0; i < n; i++) {
//             if (nums[i]  == 0) count0++;
//             else if (nums[i] == 1) count1++;
//             else count2++;
//         }
//         for (int i = 0; i < n; i++) {
//             if (i < count0) nums[i] = 0;
//             else if (i < count0 + count1) nums[i] = 1;
//             else nums[i] = 2;
//         }
//     }
// };