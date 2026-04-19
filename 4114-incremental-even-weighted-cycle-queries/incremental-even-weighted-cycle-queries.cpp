class Solution {
public:
    vector<int> parent, rank, parity;

    int find(int a) {
        if (parent[a] == a)
            return a;

        int p = parent[a];
        parent[a] = find(parent[a]);
        parity[a] ^= parity[p];

        return parent[a];
    }

    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        parent.resize(n), rank.resize(n, 0), parity.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int res = 0;

        for (auto v : edges) {
            int a = v[0], b = v[1], d = v[2];
            int par_a = find(a);
            int par_b = find(b);
            int r1 = parity[a], r2 = parity[b];

            if (par_a == par_b) {
                int p = r1 ^ r2 ^ d;
                if (p == 0) {
                    res++;
                }
            } else if (rank[par_a] > rank[par_b]) {
                res++;
                parent[par_b] = par_a;
                parity[par_b] = (parity[a] ^ parity[b] ^ d);
            } else if (rank[par_b] > rank[par_a]) {
                res++;
                parent[par_a] = par_b;
                parity[par_a] = (parity[a] ^ parity[b] ^ d);
            } else {
                res++;
                rank[par_a]++;
                parent[par_b] = par_a;
                parity[par_b] = (parity[a] ^ parity[b] ^ d);
            }
        }

        return res;
    }
};