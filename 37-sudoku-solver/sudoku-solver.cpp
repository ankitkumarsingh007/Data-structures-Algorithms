class Solution {
public:
    bool solved = false;
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
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int k = 1; k <= 9; k++) {
                        if (isValid(board, i, j, k)) {
                            board[i][j] = '0' + k;
                            solveSudoku(board);
                            if (solved)
                                return;
                            board[i][j] = '.';
                        }
                    }
                    // Once we found one empty, we put every value there and recurse till we find actual solution
                    // No need to go through each empty in one go
                    return;
                }
            }
        }
        // If no empty cells
        solved = true;
        return;
    }
};