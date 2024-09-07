// Link - https://leetcode.com/problems/linked-list-in-binary-tree/?envType=daily-question&envId=2024-09-07
// Linked List in Binary Tree


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool helper(ListNode* lNode, TreeNode* tNode) {
        if (lNode == nullptr) return true;
        if (tNode == nullptr) return false;

        if (tNode->val == lNode->val) {
            return helper(lNode->next, tNode->left) || helper(lNode->next, tNode->right);
        }
        return false;
    }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (head == nullptr) return true;
        if (root == nullptr) return false;

        return helper(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};