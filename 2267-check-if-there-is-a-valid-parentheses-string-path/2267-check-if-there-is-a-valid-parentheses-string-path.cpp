class Solution {
public:
    //Now every element is set to 0. Without doing this every element 
    //it garbage and will be undefined behavior if used.
    //now , 0 means false
    int dp[100][100][101]={};
    
    bool hasValidPath(vector<vector<char>>& grid,int i=0,int j=0,int bal=0) {
        int m=grid.size(),n=grid[0].size();
        
        bal+= (grid[i][j]=='('?1:-1);
        
        if(bal<0 || bal>(m+n)/2 || dp[i][j][bal])
            return false;
        
        dp[i][j][bal]=true;
        
        if(i==m-1 && j==n-1 && bal==0)
            return true;
        
        if(i<(m-1) && hasValidPath(grid,i+1,j,bal))
            return true;
        if(j<(n-1) && hasValidPath(grid,i,j+1,bal))
            return true;
        
        return false;
    }
};