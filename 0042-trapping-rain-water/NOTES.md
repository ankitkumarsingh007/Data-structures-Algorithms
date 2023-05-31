**We can do this problem by making 2 arrays lmax & rmax ,but try to do it in constant space & linear time**
```
int trap(vector<int>& height) {
int n=height.size();
vector<int> l(n,0),r(n,0);
for(int i=1;i<n;i++){
l[i]=max(l[i-1],height[i-1]);
}
for(int i=n-2;i>=0;i--){
r[i]=max(r[i+1],height[i+1]);
}
int res=0;
for(int i=1;i<n-1;i++){
res+=max(0,min(l[i],r[i])-height[i]);
}
return res;
}
```
​
​
**However a more intuitive code will be when we will use 2 pointer approach directly**
```
int trap(vector<int>& A) {
int n=A.size();
int left=0;
int right=n-1;
int res=0;
int maxleft=0, maxright=0;
while(left<=right){
if(A[left]<=A[right]){
if(A[left]>=maxleft) maxleft=A[left];
else res+=maxleft-A[left];
left++;
}
else{
if(A[right]>=maxright) maxright= A[right];
else res+=maxright-A[right];
right--;
}
}
return res;
}
```