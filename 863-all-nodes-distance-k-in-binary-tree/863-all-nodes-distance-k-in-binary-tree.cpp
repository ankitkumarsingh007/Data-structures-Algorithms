/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
        vector <int> v;

    void findKDistanceDownNode(TreeNode *root, int k)
    /* Recursive function to find all the nodes at distance k in the
       tree (or subtree) rooted with given root. See  */
    {
        // Base Case
        if (root == NULL || k < 0)  return;
    
        // If we reach a k distant node, add to vector
        if (k==0)
        {
            v.push_back(root->val);
            return;
        }
    
        // Recur for left and right subtrees
        findKDistanceDownNode(root->left, k-1);
        findKDistanceDownNode(root->right, k-1);
    }
    
    int findKDistanceNode(TreeNode* root, TreeNode* target , int k)
    // Finds all nodes at distance k from a given target node.
    // The k distant nodes may be upward or downward.  This function
    // Returns distance of root from target node, it returns -1 if target
    // node is not present in tree rooted with root.
    {
        // Base Case 1: If tree is empty, return -1
        if (root == NULL) return -1;
        
        // If target is same as root.  Use the downward function
        // to find all nodes at distance k in subtree rooted with
        // target or root
        if (root == target)
        {
            findKDistanceDownNode(root, k);
            return 0;
        }
        
        // Recur for left subtree
        int dl = findKDistanceNode(root->left, target, k);
        
        // Check if target node was found in left subtree
        if (dl != -1)
        {
             // If root is at distance k from target, add root value to vector
             // Note that dl is Distance of root's left child from target
             if (dl + 1 == k)
                v.push_back(root->val);
            
             // Else go to right subtree and print all k-dl-2 distant nodes
             // Note that the right child is 2 edges away from left child
             else
                findKDistanceDownNode(root->right, k-dl-2);
            
             // Add 1 to the distance and return value for parent calls
             return 1 + dl;
        }
        
        // MIRROR OF ABOVE CODE FOR RIGHT SUBTREE
        // Note that we reach here only when node was not found in left subtree
        int dr = findKDistanceNode(root->right, target, k);
        if (dr != -1)
        {
             if (dr + 1 == k)
                v.push_back(root->val);
             else
                findKDistanceDownNode(root->left, k-dr-2);
             return 1 + dr;
        }
        
        // If target was neither present in left nor in right subtree
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        v.clear();
        
        findKDistanceNode(root, target, k);
        
        sort( v.begin(), v.end() );
        
        return v;
    }
};