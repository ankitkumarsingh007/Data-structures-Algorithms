class Solution {
public:
    vector<bool> check;
    vector<vector<int>> graph;
    
    void dfs(int i){
        check[i]=false;
        
        for(int a:graph[i]){
            if(check[a])
                dfs(a);
        }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        graph.resize(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    graph[i].push_back(j);
                }
            }
        }
        
        check.clear();
        check.resize(n,true);
        
        int res=0;
        for(int i=0;i<n;i++){
            if(check[i]){
                res++;
                dfs(i);
            }
        }
        
        return res;
    }
};


