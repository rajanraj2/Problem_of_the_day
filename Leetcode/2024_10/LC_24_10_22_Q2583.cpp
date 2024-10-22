// Link - https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/?envType=daily-question&envId=2024-10-22
// K-th Largest Sum in a Binary Tree


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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            long long sum = 0;

            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                sum += (long long)node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(sum);
        }

        if (k > result.size()) return -1;
        sort(result.begin(), result.end(), greater<long long>());
        return result[k - 1];
    }
};