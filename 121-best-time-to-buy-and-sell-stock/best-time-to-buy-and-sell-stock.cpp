class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),res=0,rmax=prices[n-1];

        for(int i=n-2;i>=0;i--){
            res=max(res,rmax-prices[i]);
            rmax=max(rmax,prices[i]);
        }

        return res;
    }
};