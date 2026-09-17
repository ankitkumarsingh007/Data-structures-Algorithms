vector<long long> P[2];

int init = []() {
    long long M = 1e9;
    for (int v = 1; v < 100000; ++v) {
        string s = to_string(v);
        string r = s;
        reverse(r.begin(), r.end());
        long long a1 = stoll(s.substr(0, s.size() - 1) + r);
        long long a2 = stoll(s + r);
        if (a1 < M) P[a1 & 1].push_back(a1);
        if (a2 < M) P[a2 & 1].push_back(a2);
    }
    sort(P[0].begin(), P[0].end());
    sort(P[1].begin(), P[1].end());
    return 0;
}();

class Solution {
public:
    long long minOperations(vector<int>& A) {
        long long res = 0;
        for (int a : A) {
            auto& p = P[a & 1];
            int i = lower_bound(p.begin(), p.end(), a) - p.begin();
            if (i >= p.size()) i = p.size() - 1;
            long long d1 = abs(a - p[i]);
            long long d2 = i > 0 ? abs(a - p[i - 1]) : d1;
            res += min(d1, d2) / 2;
        }
        return res;
    }
};