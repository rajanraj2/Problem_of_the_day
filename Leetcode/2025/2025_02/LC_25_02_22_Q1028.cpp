// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/?envType=daily-question&envId=2025-02-22
// 1028. Recover a Tree From Preorder Traversal


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
        TreeNode* dfs(int &ind, string &s, int depth) {
            if (ind >= s.size()) return NULL;
    
            int count = 0;
            while (ind < s.size() && s[ind] == '-') {
                ind++;
                count++;
            }
    
            if (count != depth) {
                ind -= count;
                return NULL;
            }
    
            int digit = 0;
            while (ind < s.size() && s[ind] != '-') {
                digit = (digit * 10) + (s[ind] - '0');
                ind++;
            }
    
            TreeNode* node = new TreeNode(digit);
            node->left = dfs(ind, s, depth + 1); 
            node->right = dfs(ind, s, depth + 1);
            return node;
        }
        
        TreeNode* recoverFromPreorder(string traversal) {
            int ind = 0;
            return dfs(ind, traversal, 0);
        }
    };
    
    
    // 1. Create the root node from the first number.
    // 2. Iterate through the string, counting - to determine depth.
    // 3. If count == current depth, create a left child and move there.
    // 4. If count < current depth, backtrack until depth == count, then create a right child.
    // 5. Repeat until the string ends.
    
    
    // class Solution {
    // public:
    //     TreeNode* recoverFromPreorder(string s) {
    //         // Step 1: Extract depth-value pairs
    //         vector<pair<int, int>> vp;
    //         int i = 0;
    //         while (i < s.size()) {
    //             int depth = 0;
    //             while (i < s.size() && s[i] == '-') {
    //                 depth++;
    //                 i++;
    //             }
    //             int num = 0;
    //             while (i < s.size() && s[i] != '-') {
    //                 num = num * 10 + (s[i] - '0');
    //                 i++;
    //             }
    //             vp.push_back({depth, num});
    //         }
    
    //         // Step 2: Construct tree using a stack
    //         stack<pair<int, TreeNode*>> st;
    //         TreeNode* root = nullptr;
            
    //         for (auto it : vp) {
    //             int depth = it.first;
    //             int nodeVal = it.second;
    //             TreeNode* node = new TreeNode(nodeVal);
    
    //             while (!st.empty() && st.top().first >= depth) {
    //                 st.pop();
    //             }
    
    //             if (!st.empty()) {
    //                 TreeNode* parent = st.top().second;
    //                 if (parent->left == nullptr) {
    //                     parent->left = node;
    //                 } else {
    //                     parent->right = node;
    //                 }
    //             } else {
    //                 root = node; // Assign root for first node
    //             }
    
    //             st.push({depth, node});
    //         }
            
    //         return root;
    //     }
    // };