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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *curr=head,*res=head->next,*prev=head;
        
        curr=curr->next->next;
        res->next=prev;
        
        while(curr!=NULL && curr->next!=NULL){
            prev->next=curr->next;
            prev=curr;
            curr=curr->next->next;
            prev->next->next=prev;
        }
        
        prev->next=curr;
        
        return res;
    }
};