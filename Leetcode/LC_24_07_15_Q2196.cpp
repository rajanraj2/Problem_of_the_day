// Link - https://leetcode.com/problems/create-binary-tree-from-descriptions/description/?envType=daily-question&envId=2024-07-15
// Create binary tree from descriptions


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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> children;
        for (const auto& it : descriptions) {
            int parentVal = it[0], childVal = it[1], isLeft = it[2];

            if (nodeMap.find(parentVal) == nodeMap.end()) {
                nodeMap[parentVal] = new TreeNode(parentVal);
            }
            if (nodeMap.find(childVal) == nodeMap.end()) {
                nodeMap[childVal] = new TreeNode(childVal);
            } 

            if (isLeft) {
                nodeMap[parentVal]->left = nodeMap[childVal];
            }
            else {
                nodeMap[parentVal]->right = nodeMap[childVal];
            }
            children.insert(childVal);
        }

        TreeNode* root = NULL;
        for (const auto& node : nodeMap) {
            if (children.find(node.first) == children.end()) {
                root = node.second;
            }
        }
        return root;
    }
};