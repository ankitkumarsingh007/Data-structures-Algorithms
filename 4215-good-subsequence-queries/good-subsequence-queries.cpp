class Solution {
public:
    vector<int> st;

    void constructST(vector<int>& nums, int si, int l, int r, int p) {
        if (l == r) {
            st[si] = nums[l] % p == 0 ? nums[l] / p : 0;
            return;
        }
        int mid = l + (r - l) / 2;
        constructST(nums, 2 * si + 1, l, mid, p);
        constructST(nums, 2 * si + 2, mid + 1, r, p);
        st[si] = gcd(st[2 * si + 1], st[2 * si + 2]);
    }
    void update(int l, int r, int si, int pos, int val, int p) {
        if (pos < l || pos > r)
            return;
        if (l == r) {
            st[si] = val % p == 0 ? val / p : 0;
            return;
        }

        int mid = l + (r - l) / 2;
        update(l, mid, 2 * si + 1, pos, val, p);
        update(mid + 1, r, 2 * si + 2, pos, val, p);
        st[si] = gcd(st[2 * si + 1], st[2 * si + 2]);
    }
    bool canRemove(int si, int l, int r, int ext) {
        // Remove this exact index, external gcd should be 1
        if (l == r)
            return ext == 1;

        int mid = l + (r - l) / 2;
        // gcd when left tree intact
        int left = gcd(ext, st[2 * si + 1]);
        // gcd when right tree intact
        int right = gcd(ext, st[2 * si + 2]);

        if (left == 1 || right == 1)
            return true;

        // Case1: take full right and see if removing any element from left makes gcd 1
        // Case2: take full left and see if removing any element from right makes gcd
        return canRemove(2 * si + 1, l, mid, right) ||
               canRemove(2 * si + 2, mid + 1, r, left);
    }
    int countGoodSubseq(vector<int>& nums, int p,
                        vector<vector<int>>& queries) {
        int n = nums.size();
        st.resize(4 * n, -1);

        constructST(nums, 0, 0, n - 1, p);

        int res = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if ((nums[i] % p) == 0) {
                cnt++;
            }
        }

        for (auto v : queries) {
            nums[v[0]];
            if ((nums[v[0]] % p) == 0)
                cnt--;
            if ((v[1] % p) == 0)
                cnt++;

            nums[v[0]] = v[1];

            update(0, n - 1, 0, v[0], v[1], p);

            if (st[0] == 1) {
                if (cnt < n)
                    res++;
                else if (canRemove(0, 0, n - 1, 0))
                    res++;
            }
        }

        return res;
    }
};