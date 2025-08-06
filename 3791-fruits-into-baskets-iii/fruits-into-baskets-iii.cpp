class Solution {
public:
    vector<int> st;
    int buildTree(vector<int>& baskets, int si, int l, int r) {
        if (l == r) {
            return st[si] = baskets[l];
        }
        int mid = (l + r) / 2;

        return st[si] = max(buildTree(baskets, 2 * si + 1, l, mid),
                            buildTree(baskets, 2 * si + 2, mid + 1, r));
    }

    void update(int si, int sl, int sr, int num, bool& updated) {
        if (sl == sr) {
            if (st[si] >= num) {
                st[si] = 0;
                updated = true;
            }
            return;
        }
        if (st[si] >= num) {
            int mid = (sl + sr) / 2;
            update(2 * si + 1, sl, mid, num, updated);
            if (!updated) {
                update(2 * si + 2, mid + 1, sr, num, updated);
            }
            st[si] = max(st[2 * si + 1], st[2 * si + 2]);
        }
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

        int ht = ceil(log2(n));
        int stSize = pow(2,ht+1);
        st.resize(stSize, 0);

        buildTree(baskets, 0, 0, n - 1);

        int res = 0;
        for (int a : fruits) {
            if (st[0] >= a) {
                bool val = false;
                update(0, 0, n - 1, a, val);
            } else {
                res++;
            }
        }

        return res;
    }
};