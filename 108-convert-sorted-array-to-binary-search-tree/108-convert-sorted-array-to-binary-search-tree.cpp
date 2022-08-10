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
    TreeNode* fun(vector<int>& arr,int l,int r){
        if(l>r)
            return NULL;
        
        int m=(l+r)/2;
        
        TreeNode* curr=new TreeNode(arr[m]);
        curr->left=fun(arr,l,m-1);
        curr->right=fun(arr,m+1,r);
        
        return curr;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& arr) {
        return fun(arr,0,arr.size()-1);
    }
};