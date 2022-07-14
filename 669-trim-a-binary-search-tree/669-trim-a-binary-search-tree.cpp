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
    TreeNode* trimBST(TreeNode* root, int l, int r) {
        if(root==NULL)
        return root;
        
        root->left=trimBST(root->left,l,r);
        root->right=trimBST(root->right,l,r);
        
        if(root->val < l)
        return root->right;
        else if(root->val > r)
        return root->left;
        else
        return root;
    }
};