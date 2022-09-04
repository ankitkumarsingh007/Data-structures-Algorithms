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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
        return res;
        
        map<int,map<int,vector<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto p=q.front(); 
            q.pop();
            TreeNode* curr=p.first;
            int c=p.second.first,hd=p.second.second;
            mp[hd][c].push_back(curr->val);
            if(curr->left!=NULL)
            q.push({curr->left,{c+1,hd-1}});
            if(curr->right!=NULL)
            q.push({curr->right,{c+1,hd+1}});
        }
        for(auto p:mp)
        {
            vector<int> temp;
            for(auto a:p.second){
                auto v=a.second;
                sort(v.begin(),v.end());
                for(int x:v)
                    temp.push_back(x);
            }
            res.push_back(temp);
        }
        return res;
    }
};