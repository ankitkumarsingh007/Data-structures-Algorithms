class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(k, vector<int>(2, 0));
        for (int i = 0; i < k; i++)
            dp[i][0] = INT_MIN;

        for (int a : prices) {
            for (int i = 0; i < k; i++) {
                if (i == 0) {
                    dp[i][0] = max(dp[i][0], -a);
                } else {
                    dp[i][0] = max(dp[i][0], dp[i - 1][1] - a);
                }
                dp[i][1] = max(dp[i][1], dp[i][0] + a);
            }
        }

        return dp[k - 1][1];
    }
};