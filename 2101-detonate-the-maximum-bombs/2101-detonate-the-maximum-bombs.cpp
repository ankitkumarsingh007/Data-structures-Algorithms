class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> check;
    
    int cnt;
    
    void dfs(int i){
        cnt++;
        for(int a:adj[i]){
            if(check[a]){
                check[a]=false;
                dfs(a);
            }
        }
        return;
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        adj.clear();
        adj.resize(n);
        
        long double dis,a1,b1,a2,b2,r1,r2,val;
        
        for(int i=0;i<n;i++){
            a1=bombs[i][0],b1=bombs[i][1],r1=bombs[i][2];
            
            for(int j=i+1;j<n;j++){
                a2=bombs[j][0],b2=bombs[j][1],r2=bombs[j][2];
                
                val=(a1-a2)*(a1-a2)+(b1-b2)*(b1-b2);
                dis=sqrtl(val);
                if(dis<=r1){
                    adj[i].push_back(j);
                }
                if(dis<=r2){
                    adj[j].push_back(i);
                }
            }
        }
        
        int res=0;
        for(int i=0;i<n;i++){
            check.clear();
            check.resize(n,true);
            check[i]=false;
            cnt=0;
            dfs(i);
            res=max(res,cnt);
        }
        
        cout<<endl;
        return res;
    }
};