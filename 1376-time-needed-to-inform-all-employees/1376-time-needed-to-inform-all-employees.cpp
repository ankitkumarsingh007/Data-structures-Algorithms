class Solution {
public:
    vector<int> time;
    vector<vector<int>> tree;
    
    int dfs(int i){
        if(time[i]==0)
            return 0;
        int res=0;
        
        for(int a:tree[i]){
            res=max(res,dfs(a));
        }
        
        return res+time[i];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        tree.resize(n);
        time=informTime;
        for(int i=0;i<n;i++){
            if(i!=headID)
            tree[manager[i]].push_back(i);
        }
        
        return dfs(headID);
    }
};