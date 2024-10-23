// Link - https://leetcode.com/problems/cousins-in-binary-tree-ii/?envType=daily-question&envId=2024-10-23
// Cousins in Binary Tree II


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
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        dfs(vector<TreeNode*>{root});
        return root;
    }

private:
    void dfs(vector<TreeNode*> arr) {
        if (arr.empty()) return;

        int sum = 0;
        for (auto node : arr) {
            if (!node) continue;
            if (node->left) sum += node->left->val;
            if (node->right) sum += node->right->val;
        }

        vector<TreeNode*> childArr;
        for (auto node : arr) {
            int curSum = 0;
            if (node->left) curSum += node->left->val;
            if (node->right) curSum += node->right->val;

            if (node->left) {
                node->left->val = sum - curSum;
                childArr.push_back(node->left);
            }
            if (node->right) {
                node->right->val = sum - curSum;
                childArr.push_back(node->right);
            }
        }

        dfs(childArr);
    }
};





// class Solution {
// public:
//     TreeNode* replaceValueInTree(TreeNode* root) {
//         if (!root) return nullptr;

//         queue<TreeNode*> q;
//         int prev = root->val;
//         q.push(root);

//         while (!q.empty()) {
//             int size = q.size();
//             int curr = 0;

//             while (size > 0) {
//                 TreeNode* temp = q.front();
//                 q.pop();

//                 int leftRight = (temp->left ? temp->left->val : 0) + (temp->right ? temp->right->val : 0);

//                 if (temp->left) {
//                     temp->left->val = leftRight;
//                     q.push(temp->left);
//                 }

//                 if (temp->right) {
//                     temp->right->val = leftRight;
//                     q.push(temp->right);
//                 }

//                 curr += leftRight;
//                 temp->val = prev - temp->val;
//                 size--;
//             }

//             prev = curr;
//         }

//         return root;
//     }
// };