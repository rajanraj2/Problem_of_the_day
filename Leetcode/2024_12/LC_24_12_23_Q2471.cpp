
// https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/?envType=daily-question&envId=2024-12-23
// minimum number of operations to sort a binary tree by level


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int minSwaps(vector<int>& arr) {
        int count = 0, n = arr.size();
        vector<pair<int,int>> vec;
        for (int i = 0; i < n; i++) vec.push_back({arr[i], i});
        sort(vec.begin(), vec.end());

        for (int i = 0; i < n; i++) {
            if (vec[i].first != arr[i]) {
                swap(vec[vec[i].second], vec[i]);
                i--;
                count++;
            }
        }
        return count;
    }

public:
    int minimumOperations(TreeNode* root) {
        int result = 0;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int s = q.size();
            vector<int> arr;
            for (int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();
                arr.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result += minSwaps(arr);
        }
        return result;
    }
};