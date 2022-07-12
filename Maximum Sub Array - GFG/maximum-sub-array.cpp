// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    typedef long long ll;
	vector<int> findSubarray(int a[], int n) {
	    ll res=-1,start=-1,sz=0,curr=0;
	    
	    for(ll i=0;i<n;i++){
	        if(a[i]>=0){
	            curr=0;
	            ll j=i;
	            
	            while(j<n && a[j]>=0)
	            curr+=a[j++];
	            
	            if(curr>res)
	            start=i,res=curr,sz=j-i;
	            
	            i=j;
	        }
	    }
	    
	    if(res==-1)
	    return {-1};
	    else{
	        vector<int> v;
	        while(sz--){
	            v.push_back(a[start++]);
	        }
	        return v;
	    }
	}
};

// { Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}
  // } Driver Code Ends