// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
  typedef long long ll;
    long long findRank(string s) {
        ll n=s.length();
        vector<ll> fact(n,1);
        for(ll i=1;i<n;i++)
        {
            fact[i]=(fact[i-1]*i);
        }
        
        vector<ll> arr(256,0);
        for(ll i=0;i<n;i++)
        {
            if(arr[s[i]]==0)
            arr[s[i]]++;
            else
            return 0;
        }
        for(ll i=1;i<256;i++)
        arr[i]+=arr[i-1];
        
        
        ll res=1;
        for(ll i=0;i<n;i++)
        {
            res=(res+fact[n-1-i]*arr[s[i]-1]);
            for(ll j=s[i];j<256;j++)
            arr[j]--;
        }
        return res;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends