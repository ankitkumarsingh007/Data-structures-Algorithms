**Earlier i used code that is used to find minm no of jumps to reach end of array**
```
bool canJump(vector<int>& arr) {
int n=arr.size();
if(n==1)
return true;
int maxreach=arr[0],step=arr[0],jmp=1,i=0;
while(1)
{
if(maxreach>=(n-1))
return true;
else
jmp++;
if(step==0)
return false;
while(step--)
{
i++;
maxreach=max(maxreach,arr[i]+i);
}
step=maxreach-i;
}
}
```
​
​
**However if we just want to check if we can reach end of array or not , a simple solution is available**
```
bool canJump(vector<int>& arr) {
int n=arr.size(),i=0;
for(int reach=0;i<n && i<=reach;i++)
reach=max(reach,i+arr[i]);
return i==n;
}
```