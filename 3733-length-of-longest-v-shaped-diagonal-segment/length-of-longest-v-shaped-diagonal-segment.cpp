class Solution {
public:
    // dp[i][j][move][dir] stores the maximum length of a V-shaped segment
    // starting at cell (i,j) with a given number of allowed turns (move) and
    // current diagonal direction (dir).
    int dp[500][500][2][4];
    int r, c; // dimensions of the grid

    // fxn recursively computes the length of the valid segment from position
    // (i, j) Parameters:
    //   grid - the input grid
    //   i, j - current cell coordinates
    //   move - number of allowed turns remaining (at most 1 turn allowed)
    //   dir - current diagonal direction (0,1,2,3 represent the 4 diagonals)
    //   prev - the value of the previous cell in the sequence (to enforce the
    //   sequence rule)
    int fxn(vector<vector<int>>& grid, int i, int j, int move, int dir,
            int prev) {
        // Out-of-bound check OR if the cell equals the previous value
        // (violating the sequence) OR if the cell equals 1 (which can only be
        // the starting point)
        if (i < 0 or j < 0 or i >= r or j >= c or grid[i][j] == prev or
            grid[i][j] == 1) {
            return 0;
        }
        // If the previous cell was 1, then a cell with 0 is not allowed in the
        // sequence (since sequence should be 1,2,0,2,0,...)
        if (prev == 1 and grid[i][j] == 0)
            return 0;
        // If we've computed this state before, return its value.
        if (dp[i][j][move][dir] != -1)
            return dp[i][j][move][dir];

        int cur = grid[i][j]; // current cell's value
        int op1 = 0,
            op2 = 0; // options: turning or continuing in the same direction

        // Four cases for the current direction (0, 1, 2, 3):
        // Each case gives:
        //  - op2: Continue in the current diagonal direction.
        //  - op1: If a turn is allowed (move > 0), take a clockwise 90° turn.
        if (dir == 0) {
            // Direction 0: Primary movement is up-left: (i-1, j-1)
            // Clockwise turn from up-left becomes up-right: (i-1, j+1)
            if (move > 0) {
                op1 = fxn(grid, i - 1, j + 1, move - 1, 1, cur);
            }
            op2 = fxn(grid, i - 1, j - 1, move, 0, cur);
            return dp[i][j][move][dir] = max(op1, op2) + 1;
        } else if (dir == 1) {
            // Direction 1: Primary movement is up-right: (i-1, j+1)
            // Clockwise turn from up-right becomes down-right: (i+1, j+1)
            if (move > 0) {
                op1 = fxn(grid, i + 1, j + 1, move - 1, 2, cur);
            }
            op2 = fxn(grid, i - 1, j + 1, move, 1, cur);
            return dp[i][j][move][dir] = max(op1, op2) + 1;
        } else if (dir == 2) {
            // Direction 2: Primary movement is down-right: (i+1, j+1)
            // Clockwise turn from down-right becomes down-left: (i+1, j-1)
            if (move > 0) {
                op1 = fxn(grid, i + 1, j - 1, move - 1, 3, cur);
            }
            op2 = fxn(grid, i + 1, j + 1, move, 2, cur);
            return dp[i][j][move][dir] = max(op1, op2) + 1;
        } else { // dir == 3
            // Direction 3: Primary movement is down-left: (i+1, j-1)
            // Clockwise turn from down-left becomes up-left: (i-1, j-1)
            if (move > 0) {
                op1 = fxn(grid, i - 1, j - 1, move - 1, 0, cur);
            }
            op2 = fxn(grid, i + 1, j - 1, move, 3, cur);
            return dp[i][j][move][dir] = max(op1, op2) + 1;
        }
    }

    // Main function to calculate the length of the longest V-shaped diagonal
    // segment.
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        // Initialize the grid dimensions.
        r = grid.size();
        c = grid[0].size();
        int ans = 0;
        // Set all dp values to -1 (not computed yet)
        memset(dp, -1, sizeof(dp));

        // Traverse each cell in the grid.
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                // We only start a valid segment from a cell with value 1.
                if (grid[i][j] == 1) {
                    // Try starting in all four diagonal directions with 1 turn
                    // allowed. The starting cell (value 1) is counted
                    // separately, hence the +1.
                    ans = max(ans,
                              1 + fxn(grid, i - 1, j - 1, 1, 0,
                                      1)); // Direction 0: up-left turn option.
                    ans = max(ans,
                              1 + fxn(grid, i - 1, j + 1, 1, 1,
                                      1)); // Direction 1: up-right turn option.
                    ans =
                        max(ans,
                            1 + fxn(grid, i + 1, j + 1, 1, 2,
                                    1)); // Direction 2: down-right turn option.
                    ans = max(
                        ans, 1 + fxn(grid, i + 1, j - 1, 1, 3,
                                     1)); // Direction 3: down-left turn option.
                }
            }
        }
        // Return the maximum length found.
        return ans;
    }
};