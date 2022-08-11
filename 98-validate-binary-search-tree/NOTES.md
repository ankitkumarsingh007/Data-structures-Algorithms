**Simple recursive solution that u already knew**
```
typedef long long ll;
bool isValidBST(TreeNode* root,ll l=ll(INT_MIN)-1,ll r=ll(INT_MAX)+1) {
if(root==NULL){
return true;
}
ll v=root->val;
if(v<=l || v>=r)
return false;
return isValidBST(root->left,l,v)&&isValidBST(root->right,v,r);
}
```
​
**Go for it's iterative approach**
```
bool isValidBST(TreeNode* root) {
stack<TreeNode*> st;
TreeNode* prev=NULL;
while(root || !st.empty()){
while(root){
st.push(root);
root=root->left;
}
root=st.top();
st.pop();
if(prev && prev->val>=root->val)
return false;
prev=root;
root=root->right;
}
return true;
}
```