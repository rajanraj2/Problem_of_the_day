class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mpp1;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            mpp1[arr[i]]++;
            mpp1[target[i]]--;
        }

        for (int i = 0; i < n; i++) {
            if (mpp1[arr[i]] != 0) {
                return false;
            }
        }

        return true;

    }
};