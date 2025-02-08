// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/?envType=daily-question&envId=2025-02-07
// 3160. Find the Number of Distinct Colors Among the Balls


class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> ball, color;
        vector<int> ans;
        ans.reserve(queries.size());
        int distinct = 0;
        for(auto &q : queries) {
            int pos = q[0], c = q[1];
            if(ball.count(pos))
                if(--color[ball[pos]] == 0) distinct--;
            ball[pos] = c;
            if(++color[c] == 1) distinct++;
            ans.push_back(distinct);
        }
        return ans;
    }
};



// class Solution {
// public:
//     vector<int> queryResults(int limit, vector<vector<int>>& queries) {
//         vector<int> result(queries.size()), balls(limit + 1, -1);
//         int count = 0;

//         for (int i = 0; i < queries.size(); i++) {            
//             int ball = queries[i][0];
//             int val = queries[i][1];
//             if (balls[ball] == -1 && st.count(val) == 0) {
//                 count++;
                
//             }
//             else {
//                 int color = balls[ball];
//                 st.erase(color);

//             }
//             balls[ball] = val;
//             result[i] = count;
//         }
//         return result;
//     }
// };