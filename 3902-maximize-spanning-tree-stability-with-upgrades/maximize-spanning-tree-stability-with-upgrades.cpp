class DSU {
public:
    vector<int> rank, parent;

    DSU(int n) {
        rank.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
    }

    int find(int a) {
        if (parent[a] == a)
            return a;

        return parent[a] = find(parent[a]);
    }

    bool merge(int a, int b) {
        int par_a = find(a);
        int par_b = find(b);

        if (par_a == par_b)
            return false;

        if (rank[par_a] < rank[par_b]) {
            parent[par_a] = par_b;
        } else if (rank[par_b] < rank[par_a]) {
            parent[par_b] = par_a;
        } else {
            parent[par_a] = par_b;
            rank[par_b]++;
        }

        return true;
    }
};

class Solution {
public:
    bool check(vector<vector<int>>& edges, int n, int val, int k) {
        DSU dsu(n);
        vector<vector<int>> updatable;

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            int s = e[2], m = e[3];

            // Edge for sure a part of MST
            if (m == 1) {
                if (s < val)
                    return false;
                dsu.merge(u, v);
            } else {
                // See if this edge can be added with or without upgrade
                if (s >= val)
                    dsu.merge(u, v);
                else if (2 * s >= val)
                    updatable.push_back({u, v});
            }
        }

        for (auto& e : updatable) {
            int u = e[0], v = e[1];

            if (dsu.find(u) == dsu.find(v))
                continue;

            // Vertices not connected and can't be inlcuded too, so MST not
            // possible
            if (k <= 0)
                return false;

            k--;
            dsu.merge(u, v);
        }

        // All vertices should be connected
        int root = dsu.find(0);
        for (int i = 1; i < n; i++) {
            if (dsu.find(i) != root)
                return false;
        }

        return true;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        // First check if no cycle getting formed from required edges
        DSU dsu(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            int s = e[2], m = e[3];

            if (m == 1) {
                if (!dsu.merge(u, v))
                    return -1;
            }
        }

        // Problem is to find maximum of minimum so we use Binary search here
        // r is double of maximum allowed value, coz m can be 0 for that edge,
        // and if updatable value would be doubled
        int l = 1, r = 2 * 10e5, res = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(edges, n, mid, k)) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }
};