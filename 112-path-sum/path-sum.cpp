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
    bool hasPath(TreeNode* root, int targetSum) {
        if (!root->left && !root->right) {
            if (targetSum == root->val)
                return true;

            return false;
        }

        if (!root->left) {
            return hasPath(root->right, targetSum - root->val);
        }
        if (!root->right) {
            return hasPath(root->left, targetSum - root->val);
        }

        return hasPath(root->left, targetSum - root->val) ||
               hasPath(root->right, targetSum - root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;

        return hasPath(root, targetSum);
    }
};