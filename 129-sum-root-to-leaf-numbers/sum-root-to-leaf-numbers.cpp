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
    int sum = 0;
    void sumToLeaf(TreeNode* root, int val) {
        if (!root->left && !root->right) {
            sum += (val * 10 + root->val);
            return;
        }

        if (!root->left) {
            return sumToLeaf(root->right, val * 10 + root->val);
        }
        if (!root->right) {
            return sumToLeaf(root->left, val * 10 + root->val);
        }

        sumToLeaf(root->right, val * 10 + root->val);
        sumToLeaf(root->left, val * 10 + root->val);
    }
    int sumNumbers(TreeNode* root) {
        if (!root) {
            return 0;
        }

        sumToLeaf(root, 0);
        return sum;
    }
};