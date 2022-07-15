class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    void dfs(vector<vector<int>>& grid,int i,int j,int n,int m,int &temp)
    {
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0)
        return ;
        
        grid[i][j]=0;
        temp++;
        for(int x=0;x<4;x++)
        {
            int xx=i+dx[x];
            int yy=j+dy[x];
            dfs(grid,xx,yy,n,m,temp);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int temp=0;
                    dfs(grid,i,j,n,m,temp);
                    res=max(res,temp);
                }
            }
        }
        return res;
    }
};