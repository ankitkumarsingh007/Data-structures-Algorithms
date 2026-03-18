class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        int mx = 1, startPos = 0;

        for (int col = 1; col < n; col++) {
            int i = 0, j = col;
            while (j < n) {
                if (s[i] == s[j] && ((j - i) == 1 || dp[i + 1][j - 1] != 0)) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                    if (dp[i][j] > mx) {
                        mx = dp[i][j];
                        startPos = i;
                    }
                } else {
                    dp[i][j] = 0;
                }
                i++, j++;
            }
        }

        return s.substr(startPos, mx);
    }
};