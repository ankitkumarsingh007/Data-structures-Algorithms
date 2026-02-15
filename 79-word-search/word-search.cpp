class Solution {
public:
    int x[4] = {-1, 1, 0, 0}, y[4] = {0, 0, -1, 1};
    bool dfs(vector<vector<char>>& board, string& word, int ind, int k, int l) {
        if (ind == word.size())
            return true;
        board[k][l] = '&';
        int m = board.size(), n = board[0].size();

        for (int a = 0; a < 4; a++) {
            int i = k + x[a], j = l + y[a];
            if (i >= 0 && i < m && j >= 0 && j < n &&
                board[i][j] == word[ind]) {
                if (dfs(board, word, ind + 1, i, j))
                    return true;
            }
        }

        board[k][l] = word[ind - 1];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        int ind = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[ind] && dfs(board, word, ind + 1, i, j))
                    return true;
            }
        }

        return false;
    }
};