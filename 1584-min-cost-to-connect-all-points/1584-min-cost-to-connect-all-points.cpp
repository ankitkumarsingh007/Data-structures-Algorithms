class Solution {
public:
    //prims algorithm based solution
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        
        vector<int> key(n,INT_MAX);
        vector<bool> mset(n,false);
        int res=0;
        
        key[0]=0;
        
        for(int i=0;i<n;i++){
            int u=-1;
            for(int i=0;i<n;i++){
                if(!mset[i] && (u==-1 || key[i]<key[u]))
                    u=i;
            }
            
            mset[u]=true;
            res+=key[u];
            
            for(int i=0;i<n;i++){
                if(!mset[i])
                    key[i]=min(key[i],abs(points[i][0]-points[u][0])+abs(points[i][1]-points[u][1]));
            }
        }
        
        return res;
    }
};