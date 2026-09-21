class Solution {
public:
    typedef long long ll;
    ll sol = 0;

    // Main step where all computation happens
    // |st[j] - st[i] - goal| >= k
    // st[j] - st[i] >= goal + k → st[i] <= st[j] - goal - k, or
    // st[j] - st[i] <= goal - k → st[i] >= st[j] - goal + k

    void merge(vector<ll>& pre, int l, int mid, int r, int goal, int k) {
        // We are defining this outside, so that even when we are going through
        // 2nd part of arry totally we will go through first part of array only
        // once

        int p1 = l;
        int p2 = l;

        for (int j = mid + 1; j <= r; j++) {
            // Condn 1
            ll x = pre[j] - goal - k;

            while (p1 <= mid && pre[p1] <= x)
                p1++;

            sol += (p1 - l);

            // Condn 2
            x = pre[j] - goal + k;

            while (p2 <= mid && pre[p2] < x)
                p2++;

            sol += (mid - p2 + 1);
            // We had to find st[i] >= st[j] - goal + k, So found reverse of it
            // and no. that don't satisfy them falls under this
        }

        vector<ll> temp;

        int i = l, j = mid + 1;

        while (i <= mid && j <= r) {
            if (pre[i] <= pre[j])
                temp.push_back(pre[i++]);
            else
                temp.push_back(pre[j++]);
        }

        while (i <= mid)
            temp.push_back(pre[i++]);

        while (j <= r)
            temp.push_back(pre[j++]);

        for (int i = l, idx = 0; i <= r; i++, idx++) {
            pre[i] = temp[idx];
        }
    }

    void solve(vector<ll>& pre, int l, int r, int goal, int k) {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;
        solve(pre, l, mid, goal, k);
        solve(pre, mid + 1, r, goal, k);
        merge(pre, l, mid, r, goal, k);
    }

    long long distantSubarrays(vector<int>& nums, int goal, int k) {
        ll n = nums.size();

        if (k == 0)
            return n * (n + 1) / 2;

        vector<ll> pre;
        pre.push_back(0);
        ll sum = 0;

        for (int a : nums) {
            sum += a;
            pre.push_back(sum);
        }

        // solveing from 0->n, as when we are it ith posn, Then {0->i-1} is a
        // valid substr. So we can't only compute for i->n-1
        solve(pre, 0, n, goal, k);

        return sol;
    }
};