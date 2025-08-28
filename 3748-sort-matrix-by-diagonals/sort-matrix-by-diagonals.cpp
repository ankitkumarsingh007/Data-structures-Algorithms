class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<priority_queue<int>> lowerHalf(n);
        vector<priority_queue<int, vector<int>, greater<int>>> upperHalf(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = i - j;
                if (val >= 0) {
                    lowerHalf[val].push(grid[i][j]);
                } else {
                    upperHalf[abs(val)].push(grid[i][j]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = i - j;
                if (val >= 0) {
                    grid[i][j] = lowerHalf[val].top();
                    lowerHalf[val].pop();
                } else {
                    grid[i][j] = upperHalf[abs(val)].top();
                    upperHalf[abs(val)].pop();
                }
            }
        }

        return grid;
    }
};