class Solution {
public:
    typedef pair<int,int> pp;
    int m,n;
    
    bool isvalid(int i,int j){
        if(i>=0 && i<m && j>=0 && j<n)
            return true;
        else
            return false;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int x[8]={-1,-1,-1,0,0,1,1,1},y[8]={-1,0,1,-1,1,-1,0,1};
        
        m=grid.size(),n=grid[0].size();
        vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
        
        queue<pp> q;
        if(grid[0][0]==0){
            q.push({0,0});
            dis[0][0]=1;
            
            if(m==1 && n==1)
                return 1;
        }
        
        while(!q.empty()){
            pp p=q.front();
            q.pop();
            int a=p.first,b=p.second;
            
            for(int i=0;i<8;i++){
                int a1=a+x[i],b1=b+y[i];
                
                if(isvalid(a1,b1) && dis[a1][b1]==INT_MAX && grid[a1][b1]==0){
                    dis[a1][b1]=dis[a][b]+1;
                    q.push({a1,b1});
                    
                    if(a1==(m-1) && b1==(n-1))
                        return dis[a1][b1];
                }
            }
        }
        
        return -1;
    }
};