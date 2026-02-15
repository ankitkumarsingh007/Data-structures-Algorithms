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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode *fast = head->next, *slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *l = head, *r = slow->next;
        slow->next = NULL;

        l = sortList(l);
        r = sortList(r);

        ListNode* currHead = new ListNode(0);
        ListNode* curr = currHead;

        while (l && r) {
            if (l->val <= r->val) {
                curr->next = l;
                l = l->next;
            } else {
                curr->next = r;
                r = r->next;
            }
            curr = curr->next;
        }
        if (l)
            curr->next = l;
        if (r)
            curr->next = r;

        return currHead->next;
    }
};