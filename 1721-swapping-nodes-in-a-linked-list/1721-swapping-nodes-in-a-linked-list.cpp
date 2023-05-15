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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *h1=head,*h2=head,*h3;
        k--;
        
        while(k--){
            h1=h1->next;
        }
        
        h3=h1;
        
        while(h3->next!=NULL){
            h3=h3->next;
            h2=h2->next;
        }
        
        swap(h1->val,h2->val);
        
        return head;
    }
};