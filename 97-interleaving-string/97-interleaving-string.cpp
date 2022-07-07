class Solution {
public:
    bool isInterleave(string a, string b, string c) {
        int n1=a.size(),n2=b.size(),n3=c.size();
        
        if(n1+n2!=n3)
        return false;
        
        vector<vector<bool>> dp(n1+1,vector<bool>(n2+1,false));
        dp[0][0]=true;
        
        for(int i=1;i<=n1;i++){
            if(a[i-1]==c[i-1])
            dp[i][0]=true;
            else{
                while(i<n1)
                dp[i++][0]=false;
            }
        }
        for(int i=1;i<=n2;i++){
            if(b[i-1]==c[i-1])
            dp[0][i]=true;
            else{
                while(i<n2)
                dp[0][i++]=false;
            }
        }
        
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                int k=i+j;
                if(a[i-1]==c[k-1])
                dp[i][j]=dp[i][j]||dp[i-1][j];
                if(b[j-1]==c[k-1])
                dp[i][j]=dp[i][j]||dp[i][j-1];
            }
        }
        
        return dp[n1][n2];
    }
};