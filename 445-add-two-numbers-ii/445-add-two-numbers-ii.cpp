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
    ListNode* reverse(ListNode* head){
        ListNode *prev=NULL,*curr=head;
        
        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        
        ListNode *res=new ListNode();
        ListNode *curr=res;
        int carry=0;
        
        while(l1!=NULL || l2!=NULL){
            int a=carry;
            if(l1!=NULL)
            {
                a+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                a+=l2->val;
                l2=l2->next;
            }
            
            curr->next=new ListNode(a%10);
            curr=curr->next;
            
            carry=a/10;
        }
        if(carry!=0)
            curr->next=new ListNode(carry);
            
        
        res=reverse(res->next);
        return res;
    }
};