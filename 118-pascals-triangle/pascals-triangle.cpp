class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for (int i = 1; i <= numRows; i++) {
            vector<int> arr(i);
            for (int j = 0; j < i; j++) {
                if (j == 0 || j == (i - 1))
                    arr[j] = 1;
                else
                    arr[j] = res[i - 2][j - 1] + res[i - 2][j];
            }
            res.push_back(arr);
        }

        return res;
    }
};