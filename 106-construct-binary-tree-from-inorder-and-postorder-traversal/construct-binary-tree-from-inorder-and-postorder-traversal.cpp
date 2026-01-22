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
    int index;
    TreeNode* tree(vector<int>& inorder, vector<int>& postorder, int l, int r) {
        if (l == r) {
            return new TreeNode(postorder[index--]);
        }
        if (l > r)
            return NULL;

        int i = l;
        while (i <= r) {
            if (inorder[i] == postorder[index])
                break;
            i++;
        }

        TreeNode* curr = new TreeNode(postorder[index--]);
        TreeNode* right = tree(inorder, postorder, i + 1, r);
        TreeNode* left = tree(inorder, postorder, l, i - 1);

        curr->left = left;
        curr->right = right;

        return curr;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        index = n - 1;
        return tree(inorder, postorder, 0, n - 1);
    }
};