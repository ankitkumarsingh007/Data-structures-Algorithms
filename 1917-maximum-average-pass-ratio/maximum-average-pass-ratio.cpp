class Solution {
public:
    typedef long long ll;
    typedef pair<double, pair<ll, ll>> pp;
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        ll n = classes.size();
        priority_queue<pp> pq;
        double currRatio = 0;

        for (vector<int> v : classes) {
            ll a=v[0],b=v[1];
            currRatio += (double(v[0])) / (v[1] * n);

            if (v[1] != v[0]) {
                double addRatio = double(b - a) / (b * (b + 1));
                pq.push({addRatio, {v[0], v[1]}});
            }
        }

        while (extraStudents-- && !pq.empty()) {
            pp t = pq.top();
            pq.pop();
            double add = t.first;
            ll a = t.second.first + 1, b = t.second.second + 1;

            currRatio += add / n;

            add = double(b - a) / (b * (b + 1));
            pq.push({add, {a, b}});
        }

        return currRatio;
    }
};