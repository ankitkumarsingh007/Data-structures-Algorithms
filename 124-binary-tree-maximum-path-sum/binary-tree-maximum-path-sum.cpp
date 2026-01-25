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
    int max_sum = INT_MIN;
    int maxSum(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int lMax = maxSum(root->left);
        int rMax = maxSum(root->right);

        max_sum =
            max(max_sum,
                max(lMax + rMax + root->val,
                    max(lMax + root->val, max(rMax + root->val, root->val))));

        return max(lMax + root->val, max(rMax + root->val, root->val));
    }

    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;

        maxSum(root);
        return max_sum;
    }
};