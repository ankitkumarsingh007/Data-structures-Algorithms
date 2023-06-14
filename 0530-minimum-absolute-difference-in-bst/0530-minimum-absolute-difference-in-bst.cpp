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
    void helper(TreeNode* &root,int &prev,int &res){
        if(root==NULL)
            return;
        
        helper(root->left,prev,res);
        if(prev!=-1)
            res=min(res,root->val-prev);
        prev=root->val;
        helper(root->right,prev,res);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int res=INT_MAX,prev=-1;
        
        helper(root,prev,res);
        
        return res;
    }
};