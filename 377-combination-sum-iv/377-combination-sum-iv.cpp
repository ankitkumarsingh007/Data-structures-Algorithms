class Solution {
public:
    typedef long long ll;
    int combinationSum4(vector<int>& arr, int sum) {
        ll mod=INT_MAX;
        
        vector<ll> dp(sum+1,0);
        dp[0]=1;
        
        for(int i=1;i<=sum;i++){
            for(int x:arr){
                if(x<=i){
                    dp[i]=(dp[i]+dp[i-x]);
                    if(dp[i]>=INT_MAX)
                        dp[i]=-1;
                }    
            }
        }
        
        return dp[sum];
    }
};