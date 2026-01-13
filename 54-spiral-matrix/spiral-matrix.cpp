class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();

        int r1 = 0, r2 = m - 1, c1 = 0, c2 = n - 1;
        int t = min(m, n) / 2;

        while (t--) {
            for (int j = c1; j <= c2; j++) {
                res.push_back(matrix[r1][j]);
            }
            r1++;
            for (int i = r1; i <= r2; i++) {
                res.push_back(matrix[i][c2]);
            }
            c2--;
            for (int j = c2; j >= c1; j--) {
                res.push_back(matrix[r2][j]);
            }
            r2--;
            for (int i = r2; i >= r1; i--) {
                res.push_back(matrix[i][c1]);
            }
            c1++;
        }

        if (r1 == r2) {
            for (int j = c1; j <= c2; j++) {
                res.push_back(matrix[r1][j]);
            }
        }
        else if (c1 == c2) {
            for (int i = r1; i <= r2; i++) {
                res.push_back(matrix[i][c1]);
            }
        }

        return res;
    }
};