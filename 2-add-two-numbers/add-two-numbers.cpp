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
        if (!l1)
            return l2;

        if (!l2)
            return l1;

        ListNode *res = NULL, *head = NULL;
        int sum = 0, carry = 0;

        while (l1 && l2) {
            int a = l1->val, b = l2->val;
            l1 = l1->next, l2 = l2->next;
            sum = (a + b + carry) % 10, carry = (a + b + carry) / 10;

            if (head == NULL) {
                res = new ListNode(sum);
                head = res;
            } else {
                head->next = new ListNode(sum);
                head = head->next;
            }
        }

        while (l1) {
            int a = l1->val;
            l1 = l1->next;
            sum = (a + carry) % 10, carry = (a + carry) / 10;

            head->next = new ListNode(sum);
            head = head->next;
        }

        while (l2) {
            int a = l2->val;
            l2 = l2->next;
            sum = (a + carry) % 10, carry = (a + carry) / 10;

            head->next = new ListNode(sum);
            head = head->next;
        }

        if(carry>0){
            head->next = new ListNode(carry);
        }

        return res;
    }
};