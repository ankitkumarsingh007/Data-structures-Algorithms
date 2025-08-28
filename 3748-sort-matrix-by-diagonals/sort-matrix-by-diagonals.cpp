class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> temp;
        for (int k = 1; k < n; k++) {
            int i = 0, j = k, x = 0;
            temp.clear();

            while (j < n) {
                temp.push_back(grid[i++][j++]);
            }
            sort(temp.begin(), temp.end());
            i = 0, j = k;
            while (j < n) {
                grid[i++][j++] = temp[x++];
            }
        }

        for (int k = 0; k < n; k++) {
            int i = k, j = 0, x = 0;
            temp.clear();

            while (i < n) {
                temp.push_back(grid[i++][j++]);
            }
            sort(temp.begin(), temp.end(), greater<int>());

            i = k, j = 0;
            while (i < n) {
                grid[i++][j++] = temp[x++];
            }
        }

        return grid;
    }
};