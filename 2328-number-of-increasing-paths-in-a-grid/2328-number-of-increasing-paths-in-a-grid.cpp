int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
const int MOD = 1'000'000'007;

class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> inDegree(m, vector<int>(n));
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
            for (int di = 0; di < size(dx); di++) {
                int vi = i + dx[di], vj = j + dy[di];
                if (vi < 0 || vi >= m || vj < 0 || vj >= n) continue;
                if (grid[i][j] < grid[vi][vj]) inDegree[vi][vj]++;
            }
        }
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (inDegree[i][j] == 0) q.emplace(i, j);
        while (!q.empty()) {
            auto [ux, uy] = q.front(); q.pop();
            dp[ux][uy]++;
            dp[ux][uy] %= MOD;
            ans += dp[ux][uy];
            ans %= MOD;
            for (int di = 0; di < size(dx); di++) {
                int vx = ux + dx[di], vy = uy + dy[di];
                if (vx < 0 || vx >= m || vy < 0 || vy >= n) continue;
                if (grid[ux][uy] < grid[vx][vy]) {
                    dp[vx][vy] += dp[ux][uy];
                    dp[vx][vy] %= MOD;
                    inDegree[vx][vy]--;
                    if (inDegree[vx][vy] == 0) {
                        q.emplace(vx, vy);
                    }
                }
            }
        }
        return ans;
    }
};