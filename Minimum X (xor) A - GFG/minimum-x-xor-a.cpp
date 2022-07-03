// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int x=0;
        while(b!=0){
            b&=(b-1);
            x++;
        }
        
        int res=0;
        for(int i=31;i>=0 && x!=0;i--){
            if((a&(1<<i))!=0){
                x--;
                res=res|(1<<i);
            }
        }
        
        for(int i=0;i<32 && x!=0;i++){
            if((res&(1<<i))==0){
                x--;
                res=res|(1<<i);
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
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends