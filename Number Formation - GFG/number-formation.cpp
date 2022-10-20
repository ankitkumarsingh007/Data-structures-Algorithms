//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {

  public:
    typedef long long ll;
    int dp[61][61][61]={},cnt[61][61][61]={};
    
    ll mul[181];
    ll mod=1e9+7;
    
    //main result will be stored here
    ll final_res=0;
    
    void helper(ll x,ll y,ll z){
        if(cnt[x][y][z]!=0)
        return;
        
        ll res=0,total=0,m=x+y+z-1;
        
        ll a,b;
        
        if(x!=0){
            helper(x-1,y,z);
            a=dp[x-1][y][z],b=cnt[x-1][y][z];
            
            res+=(4*mul[m]*b+a);
            total+=b;
            
            res%=mod,total%=mod;
        }
        
        if(y!=0){
            helper(x,y-1,z);
            a=dp[x][y-1][z],b=cnt[x][y-1][z];
            
            res+=(5*mul[m]*b+a);
            total+=b;
            
            res%=mod,total%=mod;
        }
        
        if(z!=0){
            helper(x,y,z-1);
            a=dp[x][y][z-1],b=cnt[x][y][z-1];
            
            res+=(6*mul[m]*b+a);
            total+=b;
            
            res%=mod,total%=mod;
        }
        
        dp[x][y][z]=res,cnt[x][y][z]=total;
        
        final_res+=res;
        final_res%=mod;
        
        return;
    }
  
    int getSum(int x, int y, int z) {
        cnt[0][0][0]=1;
        
        mul[0]=1;
        for(int i=1;i<181;i++){
            mul[i]=(mul[i-1]*10)%mod;
        }
        
        helper(x,y,z);
        
        return final_res;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;

        Solution ob;
        cout << ob.getSum(x, y, z) << "\n";
    }
    return 0;
}

// } Driver Code Ends