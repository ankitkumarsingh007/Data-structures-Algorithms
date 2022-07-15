// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> arr) 
    {
        int n=arr.size();
        vector<int> res;
        for(int k=0;k<n;k++){
            int i=0,j=k;
            while(i<n && j>=0){
                res.push_back(arr[i++][j--]);
            }
        }
        
        for(int k=1;k<n;k++){
            int i=k,j=n-1;
            while(i<n && j>=0){
                res.push_back(arr[i++][j--]);
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
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends