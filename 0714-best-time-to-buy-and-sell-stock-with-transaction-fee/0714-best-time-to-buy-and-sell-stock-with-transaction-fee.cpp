class Solution {
    //Memoization accepted
    private:
    int f(int index, int buy, vector<int>& prices, int &fee, vector<vector<int>>&dp){
        //base case
        if(index==prices.size())
        return 0;

            if(dp[index][buy]!=-1)
            return dp[index][buy];
        if(buy==1){
            return dp[index][buy] = max(-prices[index]+f(index+1,0,prices,fee,dp), 0+f(index+1,1,prices,fee,dp));
        }
        else
        return dp[index][buy] = max(prices[index]+f(index+1,1,prices,fee,dp)-fee,0+f(index+1,0,prices,fee,dp));
    }
public:
//memoization (accepted)
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return f(0,1,prices,fee,dp);
    }
};