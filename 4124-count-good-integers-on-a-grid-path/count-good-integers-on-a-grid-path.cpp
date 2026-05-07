class Solution {
public:
    typedef long long ll;
    vector<bool> onPath;
    ll dp[16][10][2];
    string s;

    ll val(ll i, ll mx, bool t) {
        if (i == 16)
            return 1;

        if (dp[i][mx][t] != -1)
            return dp[i][mx][t];

        int lim = t ? s[i] - '0' : 9;
        ll res = 0;

        for (int x = 0; x <= lim; x++) {
            if (onPath[i]) {
                if (x >= mx)
                    res += val(i + 1, x, t && (x == lim));
            } else {
                res += val(i + 1, mx, t && (x == lim));
            }
        }

        return dp[i][mx][t] = res;
    }

    ll f(ll n) {
        if (n < 0)
            return 0;

        s = to_string(n);
        while (s.size() < 16)
            s = "0" + s;

        memset(dp, -1, sizeof(dp));

        return val(0, 0, 1);
    }

    long long countGoodIntegersOnPath(long long l, long long r,
                                      string directions) {
        onPath.resize(16, false);
        onPath[0] = true;
        int i = 0;
        for (char c : directions) {
            if (c == 'D')
                i += 4;
            else
                i++;
            onPath[i] = true;
        }
        return f(r) - f(l - 1);
    }
};