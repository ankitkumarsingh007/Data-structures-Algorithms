// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int binarySearchable(int arr[], int n) {
        vector<bool> check(n,true);
        
        int mx=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]<mx)
            check[i]=false;
            
            mx=max(mx,arr[i]);
        }
        
        int mn=arr[n-1];
        for(int i=n-2;i>=0;i--){
            if(arr[i]>mn)
            check[i]=false;
            
            mn=min(mn,arr[i]);
        }
        
        int res=0;
        for(int i=0;i<n;i++){
            res+=check[i];
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int Arr[n];
        for(int i=0;i<n;i++){
            cin >> Arr[i];
        }
        Solution obj;
        cout<<obj.binarySearchable(Arr,n)<<endl;
    }
    return 0;
}  // } Driver Code Ends