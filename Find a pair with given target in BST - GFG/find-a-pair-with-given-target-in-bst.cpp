// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000
#define MAX_SIZE 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

 // } Driver Code Ends
/*Complete the function below
Node is as follows
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int X)
    {
        stack<Node*> s1,s2;
        Node* curr1=root;
        Node* curr2=root;

        while(1)
        {
            if(curr1)
            {
                s1.push(curr1);
                curr1=curr1->left;
            }
            else if(curr2!=NULL)
            {
                s2.push(curr2);
                curr2=curr2->right;
            }
            else if(!s1.empty() && !s2.empty())
            {
                curr1=s1.top();
                curr2=s2.top();
                if(curr1==curr2)
                {
                    curr1=curr1->right;
                    curr2=curr2->left;
                    s1.pop();
                    s2.pop();
                }
                else if(curr1->data+curr2->data==X)
                    return true;
                else if(curr1->data+curr2->data<X)
                {
                    curr1=curr1->right;
                    curr2=NULL;
                    s1.pop();
                }
                else
                {
                    curr2=curr2->left;
                    curr1=NULL;
                    s2.pop();
                }
            }
            else
            return false;
    }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

       getline(cin, s);
       int k = stoi(s);
        //getline(cin, s);
       Solution obj;    
       cout << obj.isPairPresent(root, k) << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}
  // } Driver Code Ends