class Solution {
public:
    vector<vector<int>> dp;
    bool isValid(int i, int j, int n, bool rowGreater) {
        if (i < 0 || i >= n || j < 0 || j >= n) {
            return false;
        }
        if (rowGreater) {
            if (i <= j)
                return false;
        } else {
            if (i >= j)
                return false;
        }
        return true;
    }

    int getSumB(vector<vector<int>>& fruits, int i, int j, int n,
                bool rowGreater) {
        if (!isValid(i, j, n, rowGreater)) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        return dp[i][j] =
                   fruits[i][j] +
                   max(getSumB(fruits, i - 1, j + 1, n, rowGreater),
                       max(getSumB(fruits, i, j + 1, n, rowGreater),
                           getSumB(fruits, i + 1, j + 1, n, rowGreater)));
    }

    int getSumC(vector<vector<int>>& fruits, int i, int j, int n,
                bool rowGreater) {
        if (!isValid(i, j, n, rowGreater)) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        return dp[i][j] =
                   fruits[i][j] +
                   max(getSumC(fruits, i + 1, j - 1, n, rowGreater),
                       max(getSumC(fruits, i + 1, j, n, rowGreater),
                           getSumC(fruits, i + 1, j + 1, n, rowGreater)));
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int a = 0, b = 0, c = 0;
        int n = fruits.size();
        dp.resize(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            a += fruits[i][i];
        }

        b = getSumB(fruits, n - 1, 0, n, true);
        c = getSumC(fruits, 0, n - 1, n, false);

        return a + b + c;
    }
};