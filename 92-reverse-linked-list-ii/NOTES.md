**Upsolve it further so that time required is optimized**
```
ListNode* reverseBetween(ListNode* head, int left, int right) {
ListNode *h1=new ListNode(0);
h1->next=head;
ListNode *prev=h1,*curr=head;
for(int i=1;i<left;i++){
prev=curr;
curr=curr->next;
}
ListNode *save=prev,*tail=curr;
prev=NULL;
right-=left;
for(int i=0;i<=right;i++){
ListNode * next=curr->next;
curr->next=prev;
prev=curr;
curr=next;
}
tail->next=curr;
save->next=prev;
return h1->next;
}
```