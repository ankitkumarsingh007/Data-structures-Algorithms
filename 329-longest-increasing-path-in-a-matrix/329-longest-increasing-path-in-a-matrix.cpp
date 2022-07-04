class Solution {
public:
    int x[4]={-1,1,0,0},y[4]={0,0,-1,1};
    int n,m;
    vector<vector<int>> dp;
    
    bool valid(int i,int j){
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        else
            return true;
    }
    
    int dfs(vector<vector<int>>& matrix,int i,int j){
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int res=1;
        int newx,newy;
        
        for(int k=0;k<4;k++){
            newx=x[k]+i,newy=y[k]+j;
            
            if(valid(newx,newy) && matrix[newx][newy]>matrix[i][j])
                res=max(res,1+dfs(matrix,newx,newy));
        }
        
        return dp[i][j]=res;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size(),m=matrix[0].size();
        
        dp.resize(n,vector<int>(m,-1));
        
        int res=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                res=max(res,dfs(matrix,i,j));
        }
        
        return res;
    }
};