class Solution {
public:
    int x[4]={-1,1,0,0},y[4]={0,0,-1,1};
    int n,m;
    
    bool valid(int i,int j){
        if(i>=0 && i<n && j>=0 && j<m)
            return true;
        else
            return false;
    }
    
    void dfs(vector<vector<char>>& arr,int i,int j){
        arr[i][j]='0';
        
        for(int k=0;k<4;k++){
            int a=x[k]+i,b=y[k]+j;
            
            if(valid(a,b) && arr[a][b]=='1')
                dfs(arr,a,b);
        }
        return;
    }
    
    int numIslands(vector<vector<char>>& arr) {
        int cnt=0;
        n=arr.size(),m=arr[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]=='1')
                {
                    cnt++;
                    dfs(arr,i,j);
                }
            }
        }
        
        return cnt;
    }
};