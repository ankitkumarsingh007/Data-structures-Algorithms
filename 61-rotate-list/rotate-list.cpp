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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;

        ListNode *dummy = new ListNode(), *curr = head;
        int cnt = 0;
        while (curr) {
            cnt++;
            curr = curr->next;
        }

        k %= cnt;
        if (k == 0) {
            return head;
        }

        ListNode *slow = dummy, *fast = dummy;
        dummy->next = head;

        while (k--) {
            fast = fast->next;
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        dummy->next = slow->next;
        slow->next = NULL;
        fast->next = head;

        return dummy->next;
    }
};