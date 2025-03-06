class Solution {
public:
    bool isValid(vector<vector<int>>& matrix, int i, int j, int n) {
        for (int k = 0; k < i; k++) {
            if (matrix[k][j] == 1)
                return false;
        }

        int row = i - 1, col = j - 1;

        while (row >= 0 && col >= 0) {
            if (matrix[row][col] == 1)
                return false;
            row--, col--;
        }

        row = i - 1, col = j + 1;
        while (row >= 0 && col < n) {
            if (matrix[row][col] == 1)
                return false;
            row--, col++;
        }

        return true;
    }

    void solve(vector<vector<string>>& res, vector<vector<int>>& matrix, int i,
               int n) {
        if (i == n) {
            vector<string> temp;
            for (auto v : matrix) {
                string s = "";
                for (auto a : v) {
                    if (a == 1)
                        s += 'Q';
                    else
                        s += '.';
                }
                temp.push_back(s);
            }
            res.push_back(temp);

            return;
        }

        for (int j = 0; j < n; j++) {
            if (isValid(matrix, i, j, n)) {
                matrix[i][j] = 1;
                solve(res, matrix, i + 1, n);
                matrix[i][j] = 0;
            }
        }

        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        vector<vector<string>> res;

        for (int j = 0; j < n; j++) {
            matrix[0][j] = 1;
            solve(res, matrix, 1, n);
            matrix[0][j] = 0;
        }

        return res;
    }
};