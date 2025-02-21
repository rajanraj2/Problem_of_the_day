// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/?envType=daily-question&envId=2025-02-21
// 1261. Find Elements in a Contaminated Binary Tree


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
class FindElements {
    private: 
        unordered_set<int> st;
    
        void bfs(TreeNode* root) {
            queue<TreeNode*> q;
            root->val = 0;
            q.push(root);
    
            while (!q.empty()) {
                TreeNode* front = q.front();
                q.pop();
                st.insert(front->val);
                if (front->left != NULL) {
                    front->left->val = 2 * front->val + 1;
                    q.push(front->left);
                }
                if (front->right != NULL) {
                    front->right->val = 2 * front->val + 2;
                    q.push(front->right);
                }
            }
        }
    
    public:
        FindElements(TreeNode* root) { bfs(root); }
        
        bool find(int target) { return st.count(target); }
    };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */