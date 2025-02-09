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
    int findSize(ListNode* head) {
        int cnt = 0;
        while (head != NULL) {
            head = head->next;
            cnt++;
        }

        return cnt;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = findSize(head);

        int t = n / k;
        ListNode *root = NULL, *curr = head, *prev_end = NULL, *first;

        while (t--) {
            first = curr;
            ListNode *prev = NULL, *next;

            for (int i = 0; i < k; i++) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            if (prev_end != NULL) {
                prev_end->next = prev;
            } else {
                root = prev;
            }

            prev_end = first;
        }

        if (curr != NULL) {
            prev_end->next = curr;
        }

        return root;
    }
};