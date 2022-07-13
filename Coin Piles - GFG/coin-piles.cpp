// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minSteps(int A[], int N, int K) {
        
        vector<int> a(N), p(N,0);
        for(int i=0; i<N; i++)
            a[i] = A[i];
        
        sort(a.begin(),a.end());
	    
	    p[0] = a[0];
	    
	    // prefix sum
	    for(int i=1 ; i<N; i++)
	        p[i] = p[i-1] + a[i];
	    
	    int ans = INT_MAX, prev = 0;
	    
	    for(int i=0; i<N; i++)
	    {
	        //good logic to find which elements have problem with me
	        int pos = upper_bound(a.begin()+i,a.end(),a[i]+K) - a.begin();
	        
	        if(i > 0 && a[i] != a[i-1])
	            prev = p[i-1];
	        
	        //sum of prev deleted ones + sum of all elements having problem
	        //minus sum of changes required to be made
	        ans = min(ans, prev + p[N-1] - p[pos-1] - (N-pos) * (a[i]+K));
	    }
	    return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin>>N>>K;
        
        int A[N];
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.minSteps(A,N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends