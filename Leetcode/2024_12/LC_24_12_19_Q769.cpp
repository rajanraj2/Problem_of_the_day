// https://leetcode.com/problems/max-chunks-to-make-sorted/?envType=daily-question&envId=2024-12-19
// Max Chunks To Make Sorted


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count = 0, maxi = arr[0];
        for (int i = 0; i < arr.size(); i++) {
            maxi = max(maxi, arr[i]);
            if (maxi <= i) count++;
        }
        return count;
    }
};