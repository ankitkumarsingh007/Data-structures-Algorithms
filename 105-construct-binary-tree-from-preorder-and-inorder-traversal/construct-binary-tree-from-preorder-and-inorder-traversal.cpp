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
    int index = 0;
    TreeNode* tree(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        if (l == r) {
            return new TreeNode(preorder[index++]);
        }
        if (l > r) {
            return NULL;
        }

        int i = l;
        while (i <= r) {
            if (inorder[i] == preorder[index])
                break;
            i++;
        }

        TreeNode* curr = new TreeNode(preorder[index++]);
        TreeNode* left = tree(preorder, inorder, l, i - 1);
        TreeNode* right = tree(preorder, inorder, i + 1, r);
        curr->left = left;
        curr->right = right;

        return curr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return tree(preorder, inorder, 0, n - 1);
    }
};