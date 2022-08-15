**Special care to be taken**
```
typedef long long ll;
int combinationSum4(vector<int>& arr, int sum) {
vector<ll> dp(sum+1,0);
dp[0]=1;
for(int i=1;i<=sum;i++){
for(int x:arr){
if(x<=i){
dp[i]+=dp[i-x];
//bcz if it's out of range of 32 bit then it won't be part of answer
//as it's mentioned specially that result will be in 32 bit range
if(dp[i]>=INT_MAX)
dp[i]=-1;
}
}
}
return dp[sum];
}
```