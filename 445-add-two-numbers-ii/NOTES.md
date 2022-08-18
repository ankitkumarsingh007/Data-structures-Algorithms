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
```
​
*Follow part considerd here*