class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int res=INT_MIN,n=prices.size();
        
        if(k==0)
            return 0;
        
        int dp[k][2];
        
        for(int i=0;i<k;i++){
            dp[i][0]=INT_MIN;
            dp[i][1]=0;
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                if(j==0){
                    dp[j][0]=max(dp[j][0],-prices[i]);
                }
                else{
                    dp[j][0]=max(dp[j][0],dp[j-1][1]-prices[i]);
                }
                
                dp[j][1]=max(dp[j][1],dp[j][0]+prices[i]);
                // res=max(res,dp[j][1]);
            }
        }
        
        return dp[k-1][1];
    }
};