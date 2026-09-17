typedef long long ll;

vector<ll> p[2];
int precompute = []() {
    ll lim = 1e9;
    for (ll i = 1; i < 1e5; i++) {
        string s = to_string(i);
        string r = s;
        reverse(r.begin(), r.end());

        // String of odd length
        ll v1 = stoll(s.substr(0, s.size() - 1) + r);
        // String of even length
        ll v2 = stoll(s + r);

        if (v1 <= lim)
            p[v1 & 1].push_back(v1);
        if (v2 <= lim)
            p[v2 & 1].push_back(v2);
    }
    sort(p[0].begin(), p[0].end());
    sort(p[1].begin(), p[1].end());
    return 0;
}();

class Solution {
public:
    long long minOperations(vector<int>& nums) {
        ll res = 0;

        for (int a : nums) {
            auto& p1 = p[a & 1];

            int i = lower_bound(p1.begin(), p1.end(), a) - p1.begin();

            if (i >= p1.size())
                i = p1.size() - 1;

            ll d1 = abs(a - p1[i]) / 2;
            ll d2 = i > 0 ? abs(a - p1[i - 1]) / 2 : d1;

            res += min(d1, d2);
        }

        return res;
    }
};