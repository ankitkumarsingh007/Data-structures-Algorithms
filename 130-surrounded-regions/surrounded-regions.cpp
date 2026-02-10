class Solution {
public:
    int x[4] = {-1, 1, 0, 0}, y[4] = {0, 0, -1, 1};
    int m, n;

    void dfs(vector<vector<char>>& board, int i, int j, char c) {
        board[i][j] = c;

        for (int k = 0; k < 4; k++) {
            int a = i + x[k], b = j + y[k];
            if (a >= 0 && a < m && b >= 0 && b < n && board[a][b] == 'O') {
                dfs(board, a, b, c);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0, '&');
            if (board[i][n - 1] == 'O')
                dfs(board, i, n - 1, '&');
        }

        for (int j = 1; j < (n - 1); j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j, '&');
            if (board[m - 1][j] == 'O')
                dfs(board, m - 1, j, '&');
        }

        for (int i = 1; i < (m - 1); i++) {
            for (int j = 1; j < (n - 1); j++) {
                if (board[i][j] == 'O')
                    dfs(board, i, j, '#');
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '&')
                    board[i][j] = 'O';
                else if (board[i][j] == '#')
                    board[i][j] = 'X';
            }
        }

        return;
    }
};