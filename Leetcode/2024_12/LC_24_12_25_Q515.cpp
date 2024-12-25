// https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/?envType=daily-question&envId=2024-12-25
// Find Largest Value in Each Tree Row


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
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> arr;
        if (!root) return arr;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int s = q.size();
            int maxi = INT_MIN;
            for (int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();
                int value = node->val;
                maxi = max(maxi, value);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            arr.push_back(maxi);
        }
        return arr;
    }
};