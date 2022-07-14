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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* res=new ListNode(0);
        ListNode* curr=head;
        
        while(curr!=NULL){
            ListNode* temp=res;
            while(temp->next && temp->next->val < curr->val){
                temp=temp->next;
            }
            
            ListNode* next=temp->next;
            temp->next=curr;
            curr=curr->next;
            temp->next->next=next;
        }
        
        return res->next;
    }
};