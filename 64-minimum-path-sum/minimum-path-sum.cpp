class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        for (int row = 1; row < m; row++) {
            int i = row, j = 0;
            while (i >= 0 && j < n) {
                if (i == 0)
                    dp[i][j] = grid[i][j] + dp[i][j - 1];
                else if (j == 0)
                    dp[i][j] = grid[i][j] + dp[i - 1][j];
                else
                    dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
                i--,j++;
            }
        }

        for(int col=1;col<n;col++){
            int i = m-1, j=col;
            while (i >= 0 && j < n) {
                if (i == 0)
                    dp[i][j] = grid[i][j] + dp[i][j - 1];
                else if (j == 0)
                    dp[i][j] = grid[i][j] + dp[i - 1][j];
                else
                    dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
                i--,j++;
            }
        }

        return dp[m - 1][n - 1];
    }
};