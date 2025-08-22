class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        bool rowHasOne = false, colHasOne = false;

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                rowHasOne = true;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1) {
                colHasOne = true;
                break;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[0][j] = 1;
                    grid[i][0] = 1;
                }
            }
        }

        int l = 1, b = 1;
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1 || rowHasOne) {
                int j = n - 1;
                while (j > i && grid[0][j] == 0) {
                    j--;
                }
                l = (j - i + 1);
                cout << l << endl;
                break;
            }
        }

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1 || colHasOne) {
                int j = m - 1;
                while (j > i && grid[j][0] == 0) {
                    j--;
                }
                b = (j - i + 1);
                cout << b << endl;
                break;
            }
        }

        return l * b;
    }
};