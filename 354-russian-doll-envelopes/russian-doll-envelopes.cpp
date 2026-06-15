bool comp(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0])
        return a[1] > b[1];
    else
        return a[0] < b[0];
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> arr;

        int n = envelopes.size();
        for (int i = 0; i < n; i++) {
            arr.push_back(envelopes[i][1]);
        }

        vector<int> v;
        for (int a : arr) {
            if (v.size() == 0 || a > v.back())
                v.push_back(a);
            else {
                int i = lower_bound(v.begin(), v.end(), a) - v.begin();
                v[i] = a;
            }
        }

        return v.size();
    }
};