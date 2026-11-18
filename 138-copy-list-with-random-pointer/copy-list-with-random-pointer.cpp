/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
        return NULL;
        
        Node* curr = head;

        while (curr) {
            Node* next = curr->next;

            curr->next = new Node(curr->val);

            curr->next->next = next;
            curr = next;
        }

        curr = head;

        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;

            curr = curr->next->next;
        }

        Node *curr1 = head, *curr2 = head->next;
        Node* res = head->next;

        while (curr1) {
            curr1->next = curr1->next->next;

            if (curr2->next)
                curr2->next = curr2->next->next;

            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return res;
    }
};