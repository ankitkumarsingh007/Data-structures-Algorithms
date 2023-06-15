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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int sum=INT_MIN,res=0,i=1;
        
        while(!q.empty()){
            int n=q.size(),curr=0;
            TreeNode* t;
            
            while(n--){
                t=q.front();
                q.pop();
                curr+=t->val;
                
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            
            if(curr>sum)
            {
                sum=curr;
                res=i;
            }
            i++;
        }
        
        return res;
    }
};