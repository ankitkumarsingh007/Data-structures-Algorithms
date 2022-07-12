// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	int m=1e9+7;
	ll countStrings(int n) {
	    if(n<=2)
	    return n+1;
	    
	    int a=2,b=3;
	    
	    for(int i=3;i<=n;i++){
	        int temp=b;
	        
	        b=(a+b)%m;
	        a=temp;
	    }
	    
	    return b;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends