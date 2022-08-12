/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) {
           if(root==NULL)
           return root;
           if(root==n1 || root==n2)
           return root;

           TreeNode* l=lowestCommonAncestor(root->left,n1,n2);
           TreeNode* r=lowestCommonAncestor(root->right,n1,n2);
           if(l!=NULL && r!=NULL)
           return root;
           else if(l!=NULL)
           return l;
           else 
           return r;
    }
};