**Simple preorder based solution**
```
int res=0;
vector<int> cnt;
void preOrder(TreeNode* root){
if(root==NULL)
return;
cnt[root->val]++;
if(root->left==NULL && root->right==NULL){
int total=0,odd=0;
for(int i=1;i<=9;i++){
total+=cnt[i];
if(cnt[i]%2==1)
odd++;
}
if((total%2==0 && odd==0) || (total%2==1 && odd==1))
res++;
}
preOrder(root->left);
preOrder(root->right);
cnt[root->val]--;
}
int pseudoPalindromicPaths (TreeNode* root) {
cnt.clear();
cnt.resize(10,0);
preOrder(root);
return res;
}
```