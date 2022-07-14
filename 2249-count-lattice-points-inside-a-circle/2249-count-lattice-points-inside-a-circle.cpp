class Solution {
public:
    int count(int rad,int i){
        int l=0,r=rad,res=0;
        rad*=rad;
        
        while(l<=r){
            int m=(l+r)/2;
            int v=i*i+m*m;
            
            if(v>rad)
                r=m-1;
            else{
                res=m;
                l=m+1;
            }
        }
        return res;
    }
    
    int countLatticePoints(vector<vector<int>>& circles) {
        vector<vector<bool>> dp(201,vector<bool>(201,false));
        
        for(auto v:circles){
            int a=v[0],b=v[1],r=v[2];
            
            dp[a][b]=true;
            for(int i=1;i<=r;i++){
                dp[a][b+i]=dp[a][b-i]=true;
                dp[a-i][b]=dp[a+i][b]=true;
            }
            
            for(int j=1;j<r;j++){
                int cnt=count(r,j);
                for(int i=1;i<=cnt;i++){
                    dp[a+i][b+j]=dp[a+i][b-j]=true;
                    dp[a-i][b+j]=dp[a-i][b-j]=true;
                }
            }
        }
        
        int res=0;
        for(int i=0;i<201;i++){
            for(int j=0;j<201;j++)
                if(dp[i][j])
                    res++;
        }

        return res;
    }
};