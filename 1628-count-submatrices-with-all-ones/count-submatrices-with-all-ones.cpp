class Solution {
public:
    int countSubMatWithOnes(vector<int>& temp, int maxSize) {
        int n = temp.size(), res = 0;

        for (int i = maxSize; i >= 1; i--) {
            int nextSmall = n;
            for (int j = n - 1; j >= 0; j--) {
                if (temp[j] < i) {
                    nextSmall = j;
                } else {
                    res += (nextSmall - j);
                }
            }
        }

        return res;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), res = 0;

        vector<int> temp(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1)
                    temp[j] += mat[i][j];
                else
                    temp[j] = 0;
            }

            res += countSubMatWithOnes(temp, i + 1);
        }

        return res;
    }
};