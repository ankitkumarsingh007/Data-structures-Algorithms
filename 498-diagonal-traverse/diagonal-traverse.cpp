class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<vector<int>> arr(m + n);
        vector<int> res;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[i + j].push_back(mat[i][j]);
            }
        }

        for (int i = 0; i < (m + n); i++) {
            if (i % 2 == 0) {
                reverse(arr[i].begin(), arr[i].end());
            }

            for (int a : arr[i]) {
                res.push_back(a);
            }
        }

        return res;
    }
};