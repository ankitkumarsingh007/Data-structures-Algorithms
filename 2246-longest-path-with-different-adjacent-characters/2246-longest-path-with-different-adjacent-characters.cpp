struct Node{
    char c;
    vector<Node*> child;
    Node(char a){
        c=a;
    }
};

class Solution {
public:
    int res=1;
    typedef pair<int,char> pp;
    
    int helper(Node* root){
        if(root==NULL){
            return 0;
        }
        int curr=1;
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(0),pq.push(0);
        
        for(auto x:root->child){
            int t=helper(x);
            if(x->c!=root->c && t>pq.top()){
                pq.pop();
                pq.push(t);
            }
        }
        
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        
        res=max(res,curr+a+b);
        
        return max(curr+a,curr+b);
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        vector<Node*> arr(n);
        
        for(int i=0;i<n;i++){
            arr[i]=new Node(s[i]);
        }
        
        for(int i=0;i<n;i++){
            if(parent[i]==-1)
                continue;
            else{
                Node *curr=arr[parent[i]];
                curr->child.push_back(arr[i]);
            }
        }
        
        helper(arr[0]);
        
        return res;
    }
};