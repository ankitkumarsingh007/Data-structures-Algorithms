class Solution {
public:
    typedef long long ll;
    ll mod = 1e9 + 7;
    ll permute(vector<vector<ll>>& dp, vector<ll>& arr, ll pos, ll n) {
        if (n < 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        if (pos == -1) {
            return 0;
        }

        if (dp[n][pos] != -1)
            return dp[n][pos];

        return dp[n][pos] = (permute(dp, arr, pos - 1, n - arr[pos]) +
                             permute(dp, arr, pos - 1, n)) %
                            mod;
    }

    int numberOfWays(int n, int x) {
        vector<ll> arr;
        vector<vector<ll>> dp;

        ll i = 1;
        ll val = pow(i, x);
        while (val <= n) {
            arr.push_back(val);
            i++;
            val = pow(i, x);
        }

        if (arr.size() == 0)
            return 0;
        ll size = arr.size();

        dp.resize(n + 1, vector<ll>(size, -1));

        return permute(dp, arr, arr.size() - 1, n);
    }
};