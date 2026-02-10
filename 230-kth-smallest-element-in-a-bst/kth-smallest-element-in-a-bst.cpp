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
    deque<int> dq;
    int kthSmallest(TreeNode* root, int k) {
        if (!root)
            return -1;

        kthSmallest(root->right, k);

        if (dq.size() == k)
            dq.pop_back();

        dq.push_front(root->val);

        kthSmallest(root->left, k);

        return dq.back();
    }
};