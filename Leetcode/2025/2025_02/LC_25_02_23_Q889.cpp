// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
// 889. Construct Binary Tree from Preorder and Postorder Traversal


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
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            stack<TreeNode*> nodes;
            TreeNode* root = new TreeNode(preorder[0]);
            nodes.push(root);
    
            int preIndex = 1, postIndex = 0;
    
            while (!nodes.empty()) {
                TreeNode* current = nodes.top();
    
                if (current->val == postorder[postIndex]) {
                    nodes.pop();
                    postIndex++;
                } else {
                    TreeNode* newNode = new TreeNode(preorder[preIndex++]);
                    if (!current->left) current->left = newNode;
                    else current->right = newNode;
                    nodes.push(newNode);
                }
            }
            return root;
        }
    };
    
    
    // class Solution {
    //     public:
        //  TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
    //         int[] index = new int[]{0};
    //         return construct(preorder, postorder, index, 0, preorder.length - 1);
    //     }
    //     private TreeNode construct(int[] preorder, int[] postorder, int[] index, int l, int h){
    //         if(index[0] >= preorder.length || l > h)
    //             return null;
    
    //         TreeNode root = new TreeNode(preorder[index[0]++]);
    //         if(l == h) return root;
    
    //         int i;
    //         for(i = l; i <= h; i++){
    //             if(postorder[i] == preorder[index[0]]) break;
    //         }
    //         if(l <= h){
    //             root.left = construct(preorder, postorder, index, l, i);
    //             root.right = construct(preorder, postorder, index, i + 1, h - 1);
    //         }
    //         return root;
    //     }
    // }
    
    
    