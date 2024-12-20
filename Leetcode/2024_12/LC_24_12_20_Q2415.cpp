// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/?envType=daily-question&envId=2024-12-20
// Reverse Odd Levels of Binary Tree


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

// BFS

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool reversed = 0;
        while (!q.empty()) {
            int s = q.size();
            vector<TreeNode*> arr(s);
            for (int i = 0; i < s; i++) {
                auto node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                if (reversed) {
                    arr[i] = node;
                    if (i >= s / 2) swap(arr[i]->val, arr[s - i - 1]->val);
                }
            }
            reversed = !reversed;
        }
        return root;
    }
};


// DFS

// class Solution {
// private:
//     void traverseDFS(TreeNode* leftChild, TreeNode* rightChild, int level) {
//         if (leftChild == nullptr || rightChild == nullptr) return;

//         if (level % 2 == 0) {
//             int temp = leftChild->val;
//             leftChild->val = rightChild->val;
//             rightChild->val = temp;
//         }

//         traverseDFS(leftChild->left, rightChild->right, level + 1);
//         traverseDFS(leftChild->right, rightChild->left, level + 1);
//     }

// public:
//     TreeNode* reverseOddLevels(TreeNode* root) {
//         traverseDFS(root->left, root->right, 0);
//         return root;
//     }
// };