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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode *lprev = dummy, *curr = head;
        int lCount = left - 1;

        while (lCount--) {
            curr = curr->next;
            lprev = lprev->next;
        }

        ListNode *prev = NULL, *next;
        int reverseCount = right - left + 1;

        while (reverseCount--) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        lprev->next->next = curr;
        lprev->next = prev;

        return dummy->next;
    }
};