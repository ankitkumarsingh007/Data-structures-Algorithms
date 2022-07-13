// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
Node* list1=new Node(0);
       Node* list2 =new Node(0);
       Node* listmid =new Node(0);
       Node* l1=list1;
       Node* l2=list2;
       Node* lm=listmid;
       
       while(head){
           if(head->data<x){
               l1->next=head;
               l1=l1->next;
           }
           else if(head->data==x){
               lm->next=head;
               lm=lm->next;
           }
           else{
               l2->next=head;
               l2=l2->next;
           }
           head=head->next;
       }
       if(listmid->next){
           l1->next=listmid->next;
           lm->next=list2->next;
           l2->next=NULL;    
       }
       else{
           l1->next=list2->next;
           l2->next=NULL;
       }
       return list1->next;
}