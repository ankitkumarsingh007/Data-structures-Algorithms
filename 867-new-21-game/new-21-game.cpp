class Solution {
public:
    double new21Game(int n, int k, int W) {
        // Cormer cases
        if (k == 0) // If k==0 so there is no step that can be taken, so probv
                    // remains intact
            return 1;
        if ((k - 1 + W) <= n) // We are able to reach all reachable points less
                              // than or equal to n
            return 1;

        vector<double> dp(n + 1, 0);
        // Base consitions
        dp[0] = 1;
        double res = 0.0, window = 1.0;

        for (int i = 1; i <= n; i++) {
            dp[i] = window / W;

            if (i < k) // Updating windows for next iteration -> 1
                window += dp[i];
            else // Updating final result res = dp[n] + dp[n-1] + ... + dp[k]
                res += dp[i];

            if (i >= W) // Updating windows for next iteration -> 2
                window -= dp[i - W];
        }

        return res;
    }
};