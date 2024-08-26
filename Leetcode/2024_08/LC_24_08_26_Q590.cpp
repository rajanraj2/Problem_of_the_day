// Link - https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/?envType=daily-question&envId=2024-08-26
// N ary Tree Postorder Traversal


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void helper(Node* root, vector<int>& result) {
        if (!root) return;
        for (Node* child : root->children) {
            helper(child, result);
        }
        result.push_back(root->val);
    }

public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }
};