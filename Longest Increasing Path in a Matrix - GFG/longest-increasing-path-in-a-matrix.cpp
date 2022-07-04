// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int x[4]={-1,1,0,0},y[4]={0,0,-1,1};
    int n,m;
    vector<vector<int>> dp;
    
    bool valid(int i,int j){
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        else
            return true;
    }
    
    int dfs(vector<vector<int>>& matrix,int i,int j){
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int res=1;
        int newx,newy;
        
        for(int k=0;k<4;k++){
            newx=x[k]+i,newy=y[k]+j;
            
            if(valid(newx,newy) && matrix[newx][newy]>matrix[i][j])
                res=max(res,1+dfs(matrix,newx,newy));
        }
        
        return dp[i][j]=res;
    }
  
    int longestIncreasingPath(vector<vector<int>>& matrix, int N, int M) {
        n=N,m=M;
        
        dp.resize(n,vector<int>(m,-1));
        
        int res=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                res=max(res,dfs(matrix,i,j));
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends