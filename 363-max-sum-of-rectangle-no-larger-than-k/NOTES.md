**Hybrid of 2 questions**
​
*(1) Maximum sum subarray having sum less than or equal to given sum using Set*
```
typedef long long ll;
ll findMaxSubarraySum(ll arr[], ll n, ll sum)
{
set<ll> total;
total.insert(0);
ll curr=0,res=0;
for(ll i=0;i<n;i++){
curr+=arr[i];
auto it=total.lower_bound(curr-sum);
if(it!=total.end())
res=max(res,curr-*it);
total.insert(curr);
}
return res;
}
```
​
​
*(2) Maximum sum Rectangle in 2D Matrix*
```
int fun(vector<int> &temp){
int res=temp[0],curr=temp[0];
for(int i=1;i<temp.size();i++){
curr=max(curr+temp[i],temp[i]);
res=max(res,curr);
}
return res;