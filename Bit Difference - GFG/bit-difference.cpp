// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    typedef long long int ll;
    int m=1e9+7;
    int countBits(int n, long long int arr[])
    {
        ll res=0;
        for(int i=0;i<32;i++){
            ll curr=0;
            for(int j=0;j<n;j++){
                if((arr[j]&(1<<i))!=0)
                curr++;
            }
            
            res=(res+(2*curr*(n-curr)))%m;
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        long long int A[N];
        for(int i = 0;i < N; i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.countBits(N, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends