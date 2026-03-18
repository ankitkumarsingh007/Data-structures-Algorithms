class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        if (arr[0][0] == 1 || arr[m - 1][n - 1] == 1)
            return 0;

        dp[0][0] = 1;

        for (int row = 1; row < m; row++) {
            int i = row, j = 0;
            while (i >= 0 && j < n) {
                if (arr[i][j] == 0) {
                    if (i == 0)
                        dp[i][j] = dp[i][j - 1];
                    else if (j == 0)
                        dp[i][j] = dp[i - 1][j];
                    else
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
                i--, j++;
            }
        }

        for (int col = 1; col < n; col++) {
            int i = m - 1, j = col;
            while (i >= 0 && j < n) {
                if (arr[i][j] == 0) {
                    if (i == 0)
                        dp[i][j] = dp[i][j - 1];
                    else if (j == 0)
                        dp[i][j] = dp[i - 1][j];
                    else
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
                i--, j++;
            }
        }

        return dp[m - 1][n - 1];
    }
};