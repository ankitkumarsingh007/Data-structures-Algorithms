// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  typedef long long ll;
    vector<long long> distributeCandies(int n, int k) {
        int l=1,r=sqrt(2*n),end;
        while(l<=r){
            int m=(l+r)/2;
            
            int v=(m*(m+1))/2;
            
            if(v>n)
            r=m-1;
            else{
                end=m;
                l=m+1;
            }
        }
        
        vector<ll> res(k,0);
        int t=end/k;
        
        end=t*k;
        int left=n-(end*(end+1))/2;
        int curr=t*k+1;
        
        
        for(int i=0;i<k;i++){
            res[i]+=(t*(i+1));
            res[i]+=(k*t*(t-1)/2);
            
            if(left>0){
                int c=min(left,curr);
                curr++;
                left-=c;
                res[i]+=c;
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        
        Solution ob;
        vector<long long> res = ob.distributeCandies(N,K);
        
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends