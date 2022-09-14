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
    int res=0;
    vector<int> cnt;
    
    void preOrder(TreeNode* root){
        if(root==NULL)
            return;
        
        cnt[root->val]++;
        if(root->left==NULL && root->right==NULL){
            int odd=0;
            
            for(int i=1;i<=9;i++){
                if(cnt[i]%2==1)
                    odd++;
            }
            
            if(odd<=1)
                res++;
        }
        
        preOrder(root->left);
        preOrder(root->right);
        
        cnt[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        cnt.clear();
        cnt.resize(10,0);
        
        preOrder(root);
        
        return res;
    }
};