// Link - https://leetcode.com/problems/spiral-matrix-iv/description/?envType=daily-question&envId=2024-09-09
// Spiral Matrix IV


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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> result(m, vector<int> (n, -1));

        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        ListNode* temp = head;
        while (temp && (top <= bottom || left <= right)) {
            for (int i = left; i <= right; i++) {
                if (temp) {
                    result[top][i] = temp->val;
                    temp = temp->next;
                }else break;
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                if (temp) {
                    result[i][right] = temp->val;
                    temp = temp->next;
                }
                else break;
            }
            right--;
            
            for (int i = right; i >= left; i--) {
                if (temp) {
                    result[bottom][i] = temp->val;
                    temp = temp->next;
                }
                else break;
            }
            bottom--;

            for (int i = bottom; i >= top; i--) {
                if (temp) {
                    result[i][left] = temp->val;
                    temp = temp->next;
                }
                else break;
            }
            left++;
        }

        return result;
    }
};