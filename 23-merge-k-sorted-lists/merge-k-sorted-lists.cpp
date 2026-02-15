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
struct comparator {
    // Logic for minheap for val thing
    bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comparator> pq;
        ListNode* currHead = new ListNode();
        ListNode* curr = currHead;

        for (ListNode* n : lists) {
            if (n)
                pq.push(n);
        }

        while (!pq.empty()) {
            ListNode* n1 = pq.top();
            pq.pop();
            curr->next = n1;
            curr = curr->next;
            n1 = n1->next;
            if (n1)
                pq.push(n1);
        }

        return currHead->next;
    }
};