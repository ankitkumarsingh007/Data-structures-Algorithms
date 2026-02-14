class Solution {
public:
    pair<int, int> getMatrixPos(int n, int pos) {
        int i = (n - 1) - ((pos-1) / n);
        int j = (n - 1 - i) % 2 == 0 ? (pos-1) % n : (n - 1) - ((pos-1) % n);

        return {i, j};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<pair<int, int>> q;
        q.push({1, 0});
        board[n - 1][0] = 0;

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            int val = curr.first, dis = curr.second;
            q.pop();

            if (val == (n * n))
                return dis;

            for (int a = val + 1; a <= min(n * n, val + 6); a++) {
                pair<int, int> pp = getMatrixPos(n, a);
                int i = pp.first, j = pp.second;

                if (board[i][j] == -1) {
                    q.push({a, dis + 1});
                    board[i][j] = 0;
                } else if (board[i][j] != 0) {
                    q.push({board[i][j], dis + 1});
                    board[i][j] = 0;

                    // pair<int,int> reached = getMatrixPos(n,board[i][j]);
                    // board[reached.first][reached.second] = 0;
                }
            }
        }

        return -1;
    }
};