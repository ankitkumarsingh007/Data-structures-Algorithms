class Solution {
public:
    int numSquares(int n) {
	    int dp[n+1];
	    dp[0]=0;
	    dp[1]=1;
	    
	    for(int i=2;i<=n;i++){
	        int j=sqrt(i);
	        dp[i]=i;
	        
	        while(j>0){
	            dp[i]=min(dp[i],1+dp[i-j*j]);
	            j--;
	        }
	    }
	    
	    return dp[n];
    }
};