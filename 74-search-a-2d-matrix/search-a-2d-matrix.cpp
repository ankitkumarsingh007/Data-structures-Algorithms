class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        if (target < matrix[0][0] || target > matrix[m - 1][n - 1])
            return false;

        int l = 0, r = m * n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int rowInd = mid / n, colInd = mid % n;
            if (matrix[rowInd][colInd] == target) {
                return true;
            } else if (matrix[rowInd][colInd] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return false;
    }
};