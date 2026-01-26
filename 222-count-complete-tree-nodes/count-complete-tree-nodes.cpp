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
    int height(TreeNode* root) {
        int height = 0;
        while (root) {
            root = root->left;
            height++;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        int size = 0, h = height(root);
        while (root) {
            if (height(root->right) == (h - 1)) {
                size += (1 << (h - 1));
                root = root->right;
            } else {
                size += (1 << (h - 2));
                root = root->left;
            }
            h--;
        }

        return size;
    }
};