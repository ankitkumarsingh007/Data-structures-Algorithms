class Solution {
public:
    int maxHeight(vector<vector<int>>& A) {
        for (auto& a : A)
            sort(begin(a), end(a));
        
        A.push_back({0, 0, 0});
        sort(begin(A), end(A));
        int n = A.size(), res = 0;
        vector<int> dp(n);
        for (int j = 1; j < n; ++j)
            for (int i = 0; i < j; ++i)
                if (A[i][0] <= A[j][0] && A[i][1] <= A[j][1] && A[i][2] <= A[j][2]) {
                    dp[j] = max(dp[j], dp[i] + A[j][2]);
                    res = max(res, dp[j]);
                }
        return res;
    }
};