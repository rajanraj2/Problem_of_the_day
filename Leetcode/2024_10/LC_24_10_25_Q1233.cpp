// Link - https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/?envType=daily-question&envId=2024-10-25
// Remove Sub-Folders from the Filesystem


class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;

        for (const string& it : folder) {
            if (result.empty() || it.find(result.back() + "/") != 0) {
                result.push_back(it);
            }
        }

        return result;
    }
};