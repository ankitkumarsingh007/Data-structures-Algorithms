class Solution {
public:
    bool isValid(vector<vector<int>>& graph, int a, int b) {
        int n = graph.size();

        for (int j = 0; j < b; j++) {
            if (graph[a][j] == 1)
                return false;
        }

        int i = a - 1, j = b - 1;
        while (i >= 0 && j >= 0) {
            if (graph[i--][j--] == 1)
                return false;
        }
        i = a + 1, j = b - 1;

        while (i < n && j >= 0) {
            if (graph[i++][j--] == 1)
                return false;
        }

        return true;
    }

    void dfs(vector<vector<int>>& graph, int& res, int ind, int n) {
        if (ind == n) {
            res++;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isValid(graph, i, ind)) {
                graph[i][ind] = 1;
                dfs(graph, res, ind + 1, n);
                graph[i][ind] = 0;
            }
        }
        return;
    }

    int totalNQueens(int n) {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        int res = 0;
        dfs(graph, res, 0, n);

        return res;
    }
};