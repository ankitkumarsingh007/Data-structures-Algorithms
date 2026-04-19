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

    bool unify(int a, int b, int d) {
        int par_a = find(a);
        int par_b = find(b);
        if (par_a == par_b) {
            return parity[a] ^ parity[b] == d;
        }

        if (rank[par_a] > rank[par_b]) {
            parent[par_b] = par_a;
            // 1. Now this makes it such that when we calculate parity for b to
            // root_a, then parity[b] is cancelled And what remains is
            // parity[a]^w, i.e. distance from root node (a) to b through a,
            // 2. Also, the connection is from a->b, and distance from parent_b
            // to b is parity_b, so we need to add that too
            parity[par_b] = (parity[a] ^ parity[b] ^ d);
        } else if (rank[par_b] > rank[par_a]) {
            parent[par_a] = par_b;
            parity[par_a] = (parity[a] ^ parity[b] ^ d);
        } else {
            rank[par_a]++;
            parent[par_b] = par_a;
            parity[par_b] = (parity[a] ^ parity[b] ^ d);
        }
        return true;
    }

    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        parent.resize(n), rank.resize(n, 0), parity.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int res = 0;

        for (auto v : edges) {
            int a = v[0], b = v[1], d = v[2];
            if (unify(a, b, d))
                res++;
        }

        return res;
    }
};