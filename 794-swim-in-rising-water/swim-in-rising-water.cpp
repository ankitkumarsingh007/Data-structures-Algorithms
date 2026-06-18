struct Node {
    int i, j, val;
    Node(int a, int b, int c) { i = a, j = b, val = c; }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        queue<Node> q;
        int n = grid.size();

        if (n == 1)
            return 0;

        q.push(Node(0, 0, grid[0][0]));

        int x[4] = {-1, 0, 0, 1}, y[4] = {0, -1, 1, 0};

        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        dis[0][0] = grid[0][0];
        int res = n * n;

        while (!q.empty()) {
            Node curr = q.front();
            q.pop();

            int i = curr.i, j = curr.j, val = curr.val;
            if (val == dis[i][j]) {
                for (int k = 0; k < 4; k++) {
                    int a = i + x[k], b = j + y[k];
                    if (a >= 0 && a < n && b >= 0 && b < n) {
                        int d = max(grid[a][b], val);
                        if (d < dis[a][b]) {
                            dis[a][b] = d;
                            q.push(Node(a, b, d));
                        }
                    }
                }
            }
        }

        return dis[n - 1][n - 1];
    }
};