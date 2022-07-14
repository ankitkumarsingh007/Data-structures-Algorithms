class Solution {
public:
    vector<bool> visit;
    
    void dfs(vector<vector<int>> adj,int i,int v){
        visit[i]=true;
        
        for(int j=0;j<v;j++){
            if(!visit[j] && adj[i][j]==1)
            dfs(adj,j,v);
        }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& adj) {
        int v=adj.size();
        visit.resize(v,false);
        
        int res=0;
        for(int i=0;i<v;i++){
            if(!visit[i]){
                dfs(adj,i,v);
                res++;
            }
        }
        
        return res;
    }
};