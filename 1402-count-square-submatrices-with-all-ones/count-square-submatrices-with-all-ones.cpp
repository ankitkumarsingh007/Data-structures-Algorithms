class Solution {
public:
    int countSquaresPerRow(vector<int>& temp, int maxSize) {
        int n = temp.size(), res = 0;

        for (int i = maxSize; i >= 1; i--) {
            int smallerThanSize = n;
            for (int j = n - 1; j >= 0; j--) {
                if(temp[j]>=i){
                    if((smallerThanSize-(j+i))>=0)
                    res++;
                }else{
                    smallerThanSize = j;
                }
            }
        }

        return res;
    }

    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> temp(n, 0);

        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != 0) {
                    temp[j]++;
                } else {
                    temp[j] = 0;
                }
            }

            res += countSquaresPerRow(temp, i + 1);
        }

        return res;
    }
};