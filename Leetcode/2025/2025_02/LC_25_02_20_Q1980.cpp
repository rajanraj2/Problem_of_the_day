// https://leetcode.com/problems/find-unique-binary-string/?envType=daily-question&envId=2025-02-20
// 1980. Find Unique Binary String


// class Solution {
// public:
//     bool helper(string str, int n, set<string> &st, string &ans) {
//         if (str.size() == n) {
//             if (st.count(str)) return false;
//             ans = str;
//             return true;
//         }
//         if (helper(str + "0", n, st, ans)) return true;
//         if (helper(str + "1", n, st, ans)) return true;
//         return false;
//     }

//     string findDifferentBinaryString(vector<string>& nums) {
//        set<string> st(nums.begin(), nums.end());
//        string ans = "";
//        helper("", nums[0].size(), st, ans);
//        return ans;
//     }
// };


class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            int n = nums.size();
            string result = "";
            for (int i = 0; i < n; i++) {
                // Flip the i-th bit of the i-th string
                result += (nums[i][i] == '0') ? '1' : '0';
            }
            return result;
        }
    };