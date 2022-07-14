/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int> mp;
    int i=0;
    
    TreeNode* fun(vector<int>& pre, vector<int>& in,int l,int r){
        if(l>r)
            return NULL;
        
        TreeNode* curr=new TreeNode(pre[i]);
        int p=mp[pre[i++]];
        
        curr->left=fun(pre,in,l,p-1);
        curr->right=fun(pre,in,p+1,r);
        
        return curr;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=pre.size();
        
        for(int i=0;i<n;i++)
            mp[in[i]]=i;
        
        return fun(pre,in,0,n-1);
    }
};