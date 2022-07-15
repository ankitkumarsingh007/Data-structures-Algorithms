class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
       vector<int> dp(n);
       int l=0,r=0;
       dp[0]=a[0];
       
       for(int i=1;i<n;i++){
           if(a[i]>dp[r]){
               r++;
               dp[r]=a[i];
           }
           else{
               int x=upper_bound(dp.begin(),dp.begin()+r,a[i])-dp.begin();
               
               if(x!=0 && dp[x-1]==a[i])
                   continue;
               
               dp[x]=a[i];
           }
       }
       
       return r+1;
    }
};


