class Solution {
public:
    vector<vector<int>> dp;
    int fun(string& s1, string& s2, string& s3, int n1, int n2) {
        if (n1 == 0 && n2 == 0)
            return true;

        if (dp[n1][n2] != -1)
            return dp[n1][n2];

        dp[n1][n2] = 0;

        if (n1 != 0 && s1[n1 - 1] == s3[n1 + n2 - 1])
            dp[n1][n2] = max(fun(s1, s2, s3, n1 - 1, n2), dp[n1][n2]);
        if (n2 != 0 && s2[n2 - 1] == s3[n1 + n2 - 1])
            dp[n1][n2] = max(fun(s1, s2, s3, n1, n2 - 1), dp[n1][n2]);

        return dp[n1][n2];
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size();
        dp.resize(n1 + 1, vector<int>(n2 + 1, -1));

        if ((n1 + n2) != s3.size())
            return false;

        return fun(s1, s2, s3, n1, n2) > 0;
    }
};