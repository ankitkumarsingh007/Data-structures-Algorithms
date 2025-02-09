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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        ListNode *fast = head->next->next, *slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        };

        if (fast == NULL) {
            fast = slow->next;
        } else {
            fast = slow->next->next;
        }

        ListNode *curr = head, *prev = NULL, *next;

        while (prev != slow) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        };

        while (slow && fast) {
            if (slow->val == fast->val) {
                slow = slow->next;
                fast = fast->next;
            }
            else{
                return false;
            }
        }

        return slow == NULL;
    }
};