// Link - https://leetcode.com/problems/relative-sort-array/?envType=daily-question&envId=2024-06-11
// Relative Sort Array


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr2.size(); i++) {     // map to store order of elements in arr2
            mp[arr2[i]] = i;
        }

        vector<int> arr1InArr2, arr1NotInArr2;
        for (int i = 0; i < arr1.size(); i++) {
            if (mp.find(arr1[i]) != mp.end()) {
                arr1InArr2.push_back(arr1[i]);     // array containing elements present in arr2
            }
            else {
                arr1NotInArr2.push_back(arr1[i]);    // array containing elements not present in arr2
            }
        }

        sort(arr1InArr2.begin(), arr1InArr2.end(), [&mp](int a, int b) {
            return mp[a] < mp[b];    // sorting array on the basis of their order in arr2
        });

        sort(arr1NotInArr2.begin(), arr1NotInArr2.end());     // sorting array in ascending order

        // concatenate the arrays
        arr1InArr2.insert(arr1InArr2.end(), arr1NotInArr2.begin(), arr1NotInArr2.end()); 
        return arr1InArr2;
    }
};