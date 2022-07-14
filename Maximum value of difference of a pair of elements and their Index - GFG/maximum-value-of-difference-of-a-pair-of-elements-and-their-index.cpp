// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxValue(int arr[], int n) {
        vector<int> v1(n),v2(n);
        
        for(int i=0;i<n;i++)
        v1[i]=arr[i]-i,v2[i]=arr[i]+i;
        
        int a=*max_element(v1.begin(),v1.end())-*min_element(v1.begin(),v1.end());
        int b=*max_element(v2.begin(),v2.end())-*min_element(v2.begin(),v2.end());
        
        return max(a,b);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxValue(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends