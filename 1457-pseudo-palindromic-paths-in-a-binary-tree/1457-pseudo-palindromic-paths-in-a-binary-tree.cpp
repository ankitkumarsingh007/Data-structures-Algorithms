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
    //main idea is at most 1 odd occurence will e allowed
    
    int res=0;
    int cnt=0;
    
    void preOrder(TreeNode* root){
        if(root==NULL)
            return;
        
        cnt^= (1<<root->val);
        
        if(root->left==NULL && root->right==NULL){
            if(cnt==0 || (cnt&(cnt-1))==0)
                res++;
        }
        
        preOrder(root->left);
        preOrder(root->right);
        
        cnt^= (1<<root->val);
        
        return;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        preOrder(root);
        
        return res;
    }
};