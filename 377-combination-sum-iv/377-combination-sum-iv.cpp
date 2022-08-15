class Solution {
public:
    typedef long long ll;
    int combinationSum4(vector<int>& arr, int sum) {
        // sort(arr.begin(),arr.end());
        ll mod=INT_MAX;
        
        vector<ll> dp(sum+1,0);
        dp[0]=1;
        
        for(int i=1;i<=sum;i++){
            for(int x:arr){
                if(x<=i)
                    dp[i]=(dp[i]%mod+dp[i-x]%mod)%mod;
                // else
                //     break;
            }
        }
        
        return dp[sum];
    }
};