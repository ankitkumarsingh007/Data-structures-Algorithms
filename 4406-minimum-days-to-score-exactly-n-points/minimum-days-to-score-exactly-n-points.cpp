class Solution {
public:
    int minDays(int n) {
        // dp[x] = minimum days to score x; try every possible last streak length k, 
        // and take dp[x - k(k+1)/2] + k + 1 (or just k if it’s the first streak).
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int score = 1; score <= n; score++) {
            long long res = 0;

            for (int streak = 1; streak <= n; streak++) {
                res += streak;

                if (res > score)
                    break;

                if (res == score)
                    dp[score] = min(dp[score], streak);
                else if (dp[score - res] != INT_MAX)
                    dp[score] = min(dp[score], dp[score - res] + streak + 1);
            }
        }

        return dp[n];
    }
};