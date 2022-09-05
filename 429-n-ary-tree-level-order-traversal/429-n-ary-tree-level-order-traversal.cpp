/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        
        if(root==NULL)
            return res;
        
        queue<Node*> q;
        q.push(root);
        
        Node* curr;
        
        while(!q.empty()){
            int n=q.size();
            vector<int> temp;
            
            while(n--){
                curr=q.front();
                q.pop();
                
                temp.push_back(curr->val);
                
                for(Node* x:curr->children)
                    q.push(x);
            }
            
            res.push_back(temp);
        }
        
        return res;
    }
};