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
    bool isSame(TreeNode* a, TreeNode* b) {
        if (!a && !b) {
            return true;
        }

        if (!a)
            return false;
        if (!b)
            return false;

        if (a->val != b->val)
            return false;

        return isSame(a->left, b->right) && isSame(a->right, b->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        return isSame(root->left, root->right);
    }
};