class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int s0 = 0, s1 = -prices[0] - fee;

        for(int i=1;i<n;i++){
            int curr_s0 = max(s0,s1+prices[i]);
            s1 = max(s0 - prices[i] - fee, s1);
            s0 = curr_s0;
        }

        return s0;
    }
};