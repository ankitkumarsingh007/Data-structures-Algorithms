class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m=arr.size(),n=arr[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        if(arr[0][0]==0)
            dp[0][1]=1;
        else
            return 0;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(arr[i-1][j-1]==0)
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        
        return dp[m][n];
    }
};