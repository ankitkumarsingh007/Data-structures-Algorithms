class Solution {
public:
    void dfs(int a, vector<vector<int>>& adj, vector<int>& vis) {
        if (vis[a])
            return;
        vis[a] = 1;

        for (int u : adj[a]) {
            if (!vis[u])
                dfs(u, adj, vis);
        }
    }
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int res = 0;
        int n = nums.size();
        vector<vector<int>> adj(n);

        for (auto v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        int lim = pow(2, n);

        for (int i = 1; i < lim; i++) {
            vector<int> vis(n, -1);
            vector<int> b;
            int cnt = 0;

            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    b.push_back(j);
                    vis[j] = 0;
                    cnt ^= nums[j];
                }
            }
            if(b.size()>0)
            dfs(b[0], adj, vis);

            int s = 0;
            for (int v : vis) {
                if (v == 1)
                    s++;
            }

            if (s == b.size() && cnt == 0)
                res++;
        }

        return res;
    }
};