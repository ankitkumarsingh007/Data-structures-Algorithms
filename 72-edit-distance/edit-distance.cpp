class Solution {
public:
    vector<vector<int>> dp;
    int fun(string& s1, string& s2, int n1, int n2) {
        if (n1 == 0 && n2 == 0)
            return 0;

        if (dp[n1][n2] != INT_MAX)
            return dp[n1][n2];

        if (n1 != 0 && n2 != 0) {
            if (s1[n1 - 1] == s2[n2 - 1])
                dp[n1][n2] = fun(s1, s2, n1 - 1, n2 - 1);
            else
                dp[n1][n2] = min(dp[n1][n2], 1 + fun(s1, s2, n1 - 1, n2 - 1));
        }
        if (n1 != 0)
            dp[n1][n2] = min(dp[n1][n2], 1 + fun(s1, s2, n1 - 1, n2));
        if (n2 != 0)
            dp[n1][n2] = min(dp[n1][n2], 1 + fun(s1, s2, n1, n2 - 1));

        return dp[n1][n2];
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        dp.resize(n1 + 1, vector<int>(n2 + 1, INT_MAX));

        return fun(word1, word2, n1, n2);
    }
};