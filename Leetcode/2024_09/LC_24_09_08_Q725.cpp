// Link - https://leetcode.com/problems/split-linked-list-in-parts/?envType=daily-question&envId=2024-09-08
// Split Linked List in Parts


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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;
        int len = 0;
        ListNode* temp = head;

        while (temp) {
            len++;
            temp = temp->next;
        }
        int rem = len % k;
        cout << rem << endl;

        temp = head;
        while (temp) {
            int count = (rem == 0) ? 0 : 1;
            count += len / k;
            result.push_back(temp);

            while (temp && --count) {
                temp = temp->next;
            }

            if (temp != nullptr) {
                ListNode* temp2 = temp;
                temp = temp->next;
                temp2->next = nullptr;
            }
            if (rem > 0) rem--;
        }

        int left = k - result.size();
        while (left--) {
            result.push_back(nullptr);
        }

        return result;
    }
};