// Link - https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/?envType=daily-question&envId=2024-09-10
// Insert Greatest Common Divisors in Linked List


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
private:
    int gcd(int a, int b) {
        int result = min(a, b);
        while (result) {
            if (a % result == 0 && b % result == 0) break;
            result--;
        }
        return result;
    }

public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* temp = head;

        while (temp) {
            if (temp->next) {
                int value = gcd(temp->val, temp->next->val);
                ListNode* newNode = new ListNode(value);
                newNode->next = temp->next;
                temp->next = newNode;
                temp = newNode->next;
            }
            else temp = temp->next;
        }

        return head;
    }
};