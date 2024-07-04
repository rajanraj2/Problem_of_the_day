//  Link - https://leetcode.com/problems/merge-nodes-in-between-zeros/description/?envType=daily-question&envId=2024-07-04
// Merge Nodes in Between Zeros


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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (temp != NULL) {
            int sum = 0;
    
            while (temp != NULL && temp->val != 0) {
                sum += temp->val;
                temp = temp->next;
            }
            current->next = new ListNode(sum);
            current = current->next;

            if (temp != NULL) temp = temp->next;
        }
        return dummy->next;
    }
};