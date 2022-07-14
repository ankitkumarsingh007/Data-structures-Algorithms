// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    typedef long long ll;
    vector<vector<ll>> dp;
    
    ll helper(int m,int n,int x){
        if(x==0){
            if(n==0)
            return 1;
            else
            return 0;
        }
        if(x<0 || n<0)
        return 0;
        
        if(dp[n][x]!=-1)
        return dp[n][x];
        
        ll res=0;
        
        for(int i=1;i<=m;i++)
        res+=helper(m,n-1,x-i);
        
        return dp[n][x]=res;
    }
    
    long long noOfWays(int m , int n , int x) {
        dp.resize(n+1,vector<ll>(x+1,ll(-1)));
        return helper(m,n,x);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}  // } Driver Code Ends