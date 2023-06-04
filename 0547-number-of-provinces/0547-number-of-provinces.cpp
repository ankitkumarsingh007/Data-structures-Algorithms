class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<bool> &check,int i){
        check[i]=false;
        
        int n=graph.size();
        for(int j=0;j<n;j++){
            if(check[j] && graph[i][j]==1)
                dfs(graph,check,j);
        }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> check(n,true);
        
        int res=0;
        for(int i=0;i<n;i++){
            if(check[i]){
                res++;
                dfs(graph,check,i);
            }
        }
        
        return res;
    }
};


