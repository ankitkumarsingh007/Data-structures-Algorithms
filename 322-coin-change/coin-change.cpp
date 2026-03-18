class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int a : coins) {
                if ((i - a) >= 0 && dp[i - a] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - a] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};