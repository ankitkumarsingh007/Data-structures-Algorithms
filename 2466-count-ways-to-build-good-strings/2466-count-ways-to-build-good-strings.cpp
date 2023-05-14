class Solution {
public:
    typedef long long ll;
    int mod=1e9+7;

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<ll> dp(high+1,0);
        dp[0]=1;

        ll res=0;

        for(ll i=1;i<=high;i++){
            if(i>=zero)
            dp[i]+=dp[i-zero];

            if(i>=one)
            dp[i]+=dp[i-one];

            dp[i]%=mod;

            if(i>=low){
                res+=dp[i];
                res%=mod;
            }
        }

        return res;
    }
};