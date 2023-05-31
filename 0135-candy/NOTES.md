### O(N) space solution
​
int candy(vector<int>& arr) {
int n=arr.size();
vector<int> v(n,1);
for(int i=1;i<n;i++){
if(arr[i]>arr[i-1])
v[i]=max(v[i],v[i-1]+1);
}
for(int i=n-2;i>=0;i--){
if(arr[i]>arr[i+1])
v[i]=max(v[i],v[i+1]+1);
}
int res=0;
for(int a:v)
res+=a;
return res;
}
### Constant space solution
[For logic refer this](https://leetcode.com/problems/candy/discuss/2234434/C%2B%2B-oror-O(n)-Time-O(1)-Space-oror-Full-Explanation)
​