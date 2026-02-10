class Solution {
public:
    int x[4] = {-1, 1, 0, 0}, y[4] = {0, 0, -1, 1};
    int m, n;
    bool edgeElement = false;

    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i == 0 || i == (m - 1) || j == 0 || j == (n - 1))
            edgeElement = true;
        board[i][j] = '&';

        for (int k = 0; k < 4; k++) {
            int a = i + x[k], b = j + y[k];
            if (a >= 0 && a < m && b >= 0 && b < n && board[a][b] == 'O') {
                dfs(board, a, b);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    edgeElement = false;
                    dfs(board, i, j);

                    if (edgeElement) {
                        for (int k = 0; k < m; k++) {
                            for (int l = 0; l < n; l++) {
                                if (board[k][l] == '&')
                                    board[k][l] = 'O';
                            }
                        }
                    } else {
                        for (int k = 0; k < m; k++) {
                            for (int l = 0; l < n; l++) {
                                if (board[k][l] == '&')
                                    board[k][l] = 'X';
                            }
                        }
                    }
                }
            }
        }

        return;
    }
};