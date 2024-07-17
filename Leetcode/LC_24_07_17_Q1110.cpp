// Link - https://leetcode.com/problems/delete-nodes-and-return-forest/description/?envType=daily-question&envId=2024-07-17
// Delete Nodes And Return Forest


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
    TreeNode* removeNodes(TreeNode* node, unordered_set<int>& delete_set, vector<TreeNode*>& forest) {
        if (node == NULL) return NULL;

        node->left = removeNodes(node->left, delete_set, forest);
        node->right = removeNodes(node->right, delete_set, forest);

        if (delete_set.count(node->val)) {
            if (node->left != NULL) forest.push_back(node->left);
            if (node->right != NULL) forest.push_back(node->right);
            return NULL;
        }

        return node;
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;
        root = removeNodes(root, delete_set, forest);
        if (root != NULL) {
            forest.push_back(root);
        }
        return forest;
    }
};