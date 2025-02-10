/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode *fast = head, *slow = head;

        do {
            fast = fast->next->next;
            slow = slow->next;
        } while (fast && fast->next && fast != slow);

        if (fast != slow)
            return NULL;

        fast = head;

        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};