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
        //maintaining 3 stack first,second for storing input & last for result
        stack<int> st1,st2,res;
        
        //filling both stacks
        while(l1!=NULL){
            st1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL){
            st2.push(l2->val);
            l2=l2->next;
        }
        
        //filling result stack
        int carry=0,sum;
        
        while(!st1.empty() || !st2.empty()){
            sum=carry;
            if(!st1.empty()){
                sum+=st1.top();
                st1.pop();
            }
            if(!st2.empty()){
                sum+=st2.top();
                st2.pop();
            }
            
            res.push(sum%10);
            carry=sum/10;
        }
        
        if(carry!=0)
            res.push(carry);
        
        
        //making resultant linked list form result stack
        ListNode *head=new ListNode(res.top()),*curr=head;
        res.pop();
        while(!res.empty()){
            curr->next=new ListNode(res.top());
            res.pop();
            curr=curr->next;
        }
        
        return head;
    }
};