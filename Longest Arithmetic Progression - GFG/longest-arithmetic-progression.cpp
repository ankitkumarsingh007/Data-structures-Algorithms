// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int arr[], int n) {
        int res=1;

        vector<unordered_map<int,int>> dp(n);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int d=arr[i]-arr[j],curr;

                if(dp[j].find(d)==dp[j].end())
                curr=2;
                else
                curr=dp[j][d]+1;

                dp[i][d]=max(dp[i][d],curr);
                res=max(res,curr);
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
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends