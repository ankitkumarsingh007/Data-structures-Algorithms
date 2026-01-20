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
        stack<int> st;
        ListNode* curr = head;
        int pos = 1;

        while (curr) {
            if (pos >= left && pos <= right) {
                st.push(curr->val);
            }
            curr = curr->next;
            pos++;
        }

        curr = head;
        pos = 1;
        while (curr) {
            if (pos >= left && pos <= right) {
                curr->val = st.top();
                st.pop();
            }
            curr = curr->next;
            pos++;
        }

        return head;
    }
};