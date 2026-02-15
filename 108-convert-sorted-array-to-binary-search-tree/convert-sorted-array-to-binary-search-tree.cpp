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
    TreeNode* buildTree(vector<int>& nums, int l, int r) {
        if (l > r)
            return NULL;

        if (l == r) {
            return new TreeNode(nums[l]);
        }

        int mid = (l + r) / 2;
        TreeNode* left = buildTree(nums, l, mid - 1);
        TreeNode* right = buildTree(nums, mid + 1, r);

        TreeNode* curr = new TreeNode(nums[mid]);
        curr->left = left;
        curr->right = right;

        return curr;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }
};