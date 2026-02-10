/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (!root)
            return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size(), t = q.size();
            double sumValue = 0;
            while (t--) {
                TreeNode* curr = q.front();
                q.pop();
                sumValue += curr->val;

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            res.push_back(sumValue / n);
        }
        return res;
    }
};