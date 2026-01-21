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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode *prev = dummy, *curr_start=head;

        while (curr_start) {
            ListNode* curr = curr_start;
            while (curr->next && curr->next->val == curr->val) {
                curr = curr->next;
            }

            if (curr != curr_start) {
                prev->next = curr->next;
            }else{
                prev = curr;
            }
            curr_start = curr->next;
        }

        return dummy->next;
    }
};