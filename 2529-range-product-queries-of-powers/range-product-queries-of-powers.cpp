class Solution {
public:
    typedef long long ll;
    ll mod = 1e9 + 7;
    ll query(vector<ll>& st, ll si, ll l, ll r, ll start, ll end) {
        if (l > end || r < start) {
            return 1;
        }
        if (l >= start && r <= end) {
            return st[si];
        }

        ll mid = (l + r) / 2;
        return (query(st, 2 * si + 1, l, mid, start, end) *
                query(st, 2 * si + 2, mid + 1, r, start, end)) %
               mod;
    }
    ll build(vector<ll>& st, vector<ll>& arr, ll si, ll l, ll r) {
        if (l == r) {
            return st[si] = arr[l];
        }

        ll mid = (l + r) / 2;

        build(st, arr, 2 * si + 1, l, mid),
            build(st, arr, 2 * si + 2, mid + 1, r);

        return st[si] = (st[2 * si + 1] * st[2 * si + 2]) % mod;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<ll> arr;
        ll val = 1, len = log2(n);

        for (int i = 0; i <= len; i++) {
            if (((1 << i) & n) != 0) {
                arr.push_back(val);
            }
            val = (val * 2) % mod;
        }

        ll size = arr.size();
        ll ht = ceil(log2(size));
        ll stSize = pow(2, ht + 1);

        vector<ll> st(stSize, -1);
        build(st, arr, 0, 0, size - 1);

        vector<int> res;
        for (auto a : queries) {
            res.push_back(query(st, 0, 0, size - 1, a[0], a[1]));
        }

        return res;
    }
};