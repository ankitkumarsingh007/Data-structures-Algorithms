class Solution {
public:
    int res;
    int m, n;
    int x[4] = {0, 0, -1, 1}, y[4] = {-1, 1, 0, 0};
    vector<vector<int>> dp;

    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if (dp[i][j] != -1)
            return dp[i][j];

        int currMax = 0;
        for (int k = 0; k < 4; k++) {
            int a = x[k] + i, b = y[k] + j;
            if (a >= 0 && a < m && b >= 0 && b < n &&
                matrix[a][b] > matrix[i][j]) {
                currMax = max(currMax, dfs(matrix, a, b));
            }
        }
        return dp[i][j] = currMax + 1;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 1;
        m = matrix.size(), n = matrix[0].size();
        dp.resize(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dfs(matrix, i, j));
            }
        }

        return res;
    }
};