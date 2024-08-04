// Link - https://leetcode.com/problems/sort-the-people/?envType=daily-question&envId=2024-07-22
// Sort the People


class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
         int n = names.size();
         vector<pair<int, string>> mpp;
         for (int i = 0; i < n; i++) {
            mpp.push_back({heights[i], names[i]});
         }
         sort(mpp.begin(), mpp.end(), [](const pair<int, string>& a,const pair<int, string>& b) {
            return a.first > b.first;
         });

        vector<string> result;
         for (auto it : mpp) {
            result.push_back(it.second);
         }
        return result;
    }
};


// class Solution {
// public:
//     vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
//         int n = names.size();
//         unordered_map<int, string> mpp;
        
//         for (int i = 0; i < n; i++) {
//             mpp[heights[i]] = names[i];
//         }
//         sort(heights.rbegin(), heights.rend());
//         for (int i = 0; i < n; i++) {
//             names[i] = mpp[heights[i]];
//         }
//         return names;
//     }
// };