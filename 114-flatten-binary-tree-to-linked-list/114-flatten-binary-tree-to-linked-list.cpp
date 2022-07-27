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
    TreeNode* end(TreeNode* root)
    {
        while(root->right!=NULL)
            root=root->right;
        return root;
    }
    TreeNode* fun(TreeNode* root)
    {
        if(root==NULL)
            return root;
        TreeNode* temp=fun(root->left);
        TreeNode* right=fun(root->right);
        root->right=temp;
        root->left=NULL;
        end(root)->right=right;
        return root;
    }
    void flatten(TreeNode* root) {
        fun(root);
        return;
    }
};