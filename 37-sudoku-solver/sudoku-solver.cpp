class Solution {
public:
    bool isValid(vector<vector<char>>& board, int i, int j, int k) {
        char c = char(k + '0');
        for (int x = 0; x < 9; x++) {
            if (board[x][j] == c)
                return false;
        }

        for (int x = 0; x < 9; x++) {
            if (board[i][x] == c)
                return false;
        }

        int rowStart = i - i % 3, colStart = j - j % 3;

        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                int a = rowStart + x, b = colStart + y;
                if (board[a][b] == c)
                    return false;
            }
        }

        return true;
    }

    void solve(vector<vector<char>>& board, bool& solutionFound) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int k = 1; k <= 9; k++) {
                        if (!solutionFound && isValid(board, i, j, k)) {
                            board[i][j] = char(k + '0');
                            solve(board, solutionFound);
                            if (!solutionFound)
                                board[i][j] = '.';
                        }
                    }

                    return;
                }
            }
        }
        solutionFound = true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        bool solutionFound = false;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int k = 1; k <= 9; k++) {
                        if (isValid(board, i, j, k)) {
                            board[i][j] = char(k + '0');
                            solve(board, solutionFound);
                        }
                    }
                    return;
                }
            }
        }

        return;
    }
};