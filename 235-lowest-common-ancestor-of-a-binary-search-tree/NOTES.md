**I Understood question wrongly , this code is specifically for binary tree**
```
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) {
if(root==NULL)
return root;
if(root==n1 || root==n2)
return root;
​
TreeNode* l=lowestCommonAncestor(root->left,n1,n2);
TreeNode* r=lowestCommonAncestor(root->right,n1,n2);
if(l!=NULL && r!=NULL)
return root;
else if(l!=NULL)
return l;
else
return r;
}
```
​
**But it was given that we have a binary tree , so go accordingly**
```
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
TreeNode* cur = root;
while (true) {
if (p -> val < cur -> val && q -> val < cur -> val) {
cur = cur -> left;
} else if (p -> val > cur -> val && q -> val > cur -> val) {
cur = cur -> right;
} else {
break;
}
}
return cur;
}
```