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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        }

        int carry = 0, digit;
        ListNode *root = NULL, *curr = root;

        while (l1 && l2) {
            digit = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;

            if (root == NULL) {
                root = new ListNode(digit);
                curr = root;
            } else {
                curr->next = new ListNode(digit);
                curr = curr->next;
            }
        }

        while (l1) {
            digit = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            l1 = l1->next;

            curr->next = new ListNode(digit);
            curr = curr->next;
        }

        while (l2) {
            digit = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
            l2 = l2->next;

            curr->next = new ListNode(digit);
            curr = curr->next;
        }

        if (carry != 0) {
            curr->next = new ListNode(carry);
        }

        return root;
    }
};