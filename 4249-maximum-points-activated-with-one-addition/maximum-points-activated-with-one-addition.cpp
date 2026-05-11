class Solution {
public:
    int sz;

    void dfs(
        int i,
        unordered_map<int, vector<int>>& adjX,
        unordered_map<int, vector<int>>& adjY,
        unordered_set<int>& usedX,
        unordered_set<int>& usedY,
        vector<int>& vis,
        vector<vector<int>>& points
    ) {
        vis[i] = 1;
        sz++;

        int x = points[i][0];
        int y = points[i][1];

        // Process this x-coordinate only once
        if (!usedX.count(x)) {
            usedX.insert(x);

            for (int j : adjX[x]) {
                if (!vis[j]) {
                    dfs(j, adjX, adjY, usedX, usedY, vis, points);
                }
            }
        }

        // Process this y-coordinate only once
        if (!usedY.count(y)) {
            usedY.insert(y);

            for (int j : adjY[y]) {
                if (!vis[j]) {
                    dfs(j, adjX, adjY, usedX, usedY, vis, points);
                }
            }
        }
    }

    int maxActivated(vector<vector<int>>& points) {
        int n = points.size();

        unordered_map<int, vector<int>> adjX, adjY;

        for (int i = 0; i < n; i++) {
            adjX[points[i][0]].push_back(i);
            adjY[points[i][1]].push_back(i);
        }

        vector<int> vis(n, 0);

        unordered_set<int> usedX, usedY;

        vector<int> comps;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                sz = 0;
                dfs(i, adjX, adjY, usedX, usedY, vis, points);
                comps.push_back(sz);
            }
        }

        sort(comps.begin(), comps.end(), greater<int>());

        // Add one new point connecting best possible components
        if (comps.size() == 1)
            return comps[0] + 1;

        return comps[0] + comps[1] + 1;
    }
};