// Link - https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/?envType=daily-question&envId=2024-09-06
// Delete Nodes From Linked List Present in Array


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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (head == nullptr) return head;

        set<int> st;
        for (auto it : nums) {
            st.insert(it);
        }
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* temp = dummy;

        while (temp->next) {
            if (st.find(temp->next->val) != st.end()) {
                ListNode* deleteNode = temp->next;
                cout << deleteNode->val << endl;
                temp->next = temp->next->next;
                deleteNode->next = nullptr;
                delete deleteNode;
                continue;
            }
            temp = temp->next;
        }

        return dummy->next;
    }
};


// class Solution {
// public:
//     ListNode* modifiedList(vector<int>& nums, ListNode* head) {
//         set<int> st(nums.begin(), nums.end());
//         ListNode dummy(0);
//         dummy.next = head;
//         ListNode* prev = &dummy;
//         ListNode* temp = head;
        
//         while (temp != NULL) {
//             if (st.find(temp->val) != st.end()) {
//                 prev->next = temp->next;
//             }
//             else {
//                 prev = temp;
//             }
//             temp = temp->next;
//         }
//         return dummy.next;
//     }
// };