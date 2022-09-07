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
    string tree2str(TreeNode* root) {
        if(root==NULL)
            return "";
        
        string s=to_string(root->val),l=tree2str(root->left),r=tree2str(root->right);
        
        if(l!="" || r!="")
        {
            s+='(';
            s+=l;
            s+=')';
        }
        
        if(r!="")
        {
            s+='(';
            s+=r;
            s+=')';
        }
        
        return s;
    }
};