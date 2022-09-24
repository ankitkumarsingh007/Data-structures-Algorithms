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
    vector<vector<int>> res;
    vector<int> temp;
    int sum=0,target;
    
    void fun(TreeNode* root){
        if(root==NULL)
            return;
        sum+=root->val;
        temp.push_back(root->val);
        
        if(!root->left && !root->right){
            if(sum==target)
                res.push_back(temp);
        }
        
        fun(root->left);
        fun(root->right);
        
        temp.pop_back();
        sum-=root->val;
        
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        res.clear();
        temp.clear();
        target=targetSum;
        
        fun(root);
        
        return res;
    }
};