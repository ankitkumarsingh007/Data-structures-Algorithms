class Solution {
public:
    vector<vector<double>> dp;
    double probCal(int a, int b) {
        if (a <= 0 && b <= 0) {
            return 0.5;
        }
        if (a <= 0) {
            return 1.0;
        }
        if (b <= 0) {
            return 0;
        }

        if (dp[a][b] != -1) {
            return dp[a][b];
        }

        double res = 0;

        res += 0.25 * (probCal(a - 4, b));
        res += 0.25 * (probCal(a - 3, b - 1));
        res += 0.25 * (probCal(a - 2, b - 2));
        res += 0.25 * (probCal(a - 1, b - 3));

        return dp[a][b] = res;
    }
    double soupServings(int n) {
        if (n >= 5000) {
            return 1.0;
        }
        n = ceil(n / 25.0);
        dp.resize(n + 1, vector<double>(n + 1, -1));

        return probCal(n, n);
    }
};