// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/?envType=daily-question&envId=2025-03-02
// 2570. Merge Two 2D Arrays by Summing Values


class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            int m = nums1.size(), n = nums2.size();
            vector<vector<int>> result;
            result.reserve(m + n);
            int i = 0, j = 0;
    
            while (i < m && j < n) {
                if (nums1[i][0] == nums2[j][0]) {
                    int val = nums1[i][1] + nums2[j++][1];
                    result.push_back({nums1[i++][0], val});
                }
                else if (nums1[i][0] < nums2[j][0]) {
                    result.push_back(nums1[i++]);
                }
                else {
                    result.push_back(nums2[j++]);
                }
            }
    
            while (i < m) result.push_back(nums1[i++]);
            while (j < n) result.push_back(nums2[j++]);
            return result;
        }
    };