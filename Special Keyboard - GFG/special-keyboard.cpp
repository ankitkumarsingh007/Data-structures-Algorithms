// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    typedef long long int ll;
    long long int optimalKeys(int n){
        if(n<=3)
        return n;
        
        vector<ll> dp(n+1);
        dp[1]=1,dp[2]=2,dp[3]=3;
        
        for(ll i=4;i<=n;i++){
            dp[i]=i;
            for(ll j=i-3;j>=1;j--)
            dp[i]=max(dp[i],dp[j]*(i-1-j));
        }
        
        return dp[n];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends