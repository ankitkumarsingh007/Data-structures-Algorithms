class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m=arr.size(),n=arr[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        if(arr[0][0]==0)
            dp[0][0]=1;
        else
            return 0;
        
        for(int i=1;i<m;i++){
            if(arr[i][0]==0)
                dp[i][0]=1;
            else
                break;
        }
        for(int i=1;i<n;i++){
            if(arr[0][i]==0)
                dp[0][i]=1;
            else
                break;
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(arr[i][j]==0)
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};