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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
            return head;

        int cnt = 0;
        ListNode* h1 = head;

        while (h1) {
            h1 = h1->next;
            cnt++;
        }

        ListNode* dummy = new ListNode();
        dummy->next = head;

        int t = cnt / k;
        ListNode *prevTail = dummy, *curr_head = head, *prev = NULL,
                 *curr = head, *next = NULL;

        while (t--) {
            for (int i = 0; i < k; i++) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            prevTail->next = prev;
            prevTail = curr_head;
            curr_head = curr;
        }

        prevTail->next = curr;
        return dummy->next;
    }
};