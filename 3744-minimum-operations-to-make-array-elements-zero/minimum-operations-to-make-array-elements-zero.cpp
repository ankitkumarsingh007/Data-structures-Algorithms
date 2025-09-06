class Solution {
public:
    typedef long long ll;

    long long totalCount(vector<ll>& arr, ll n) {
        ll val = log(n) / log(4);

        return arr[val] + (n - pow(4, val) + 1) * (val + 1);
    }

    long long minOperations(vector<vector<int>>& queries) {
        ll n = queries.size();
        vector<ll> arr(17);
        arr[0] = 0;

        for (int i = 1; i < 17; i++) {
            arr[i] = (pow(4, i - 1) * 3) * i;
            arr[i] += arr[i - 1];
        }

        ll res = 0, curr = 0;
        for (auto v : queries) {
            curr = totalCount(arr, v[1]) -
                   (v[0] == 1 ? 0 : totalCount(arr, v[0] - 1));
            res += (curr + 1) / 2;
        }

        return res;
    }
};