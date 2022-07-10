// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int m,n;
    int xx[2]={1,0},yy[2]={0,1};
    bool valid(int i,int j){
        if(i>=0 && i<m && j>=0 && j<n)
            return true;
        return false;
    }
    void fun(vector<vector<int> > & mat,vector<vector <int> > &res,vector<int> &temp,int x,int y){
        if(x==m-1 && y==n-1)
        {
            res.push_back(temp);
            return;
        }
        
        for(int k=0;k<2;k++){
            int i=x+xx[k],j=y+yy[k];
            if(valid(i,j))
            {
                temp.push_back(mat[i][j]);
                fun(mat,res,temp,i,j);
                temp.pop_back();
            }
        }
        return;
    }
    
    vector<vector<int>> findAllPossiblePaths(int M, int N, vector<vector<int>> &mat)
    {
        m=M,n=N;
        vector<vector <int> > res;
        vector<int> temp;
        
        temp.push_back(mat[0][0]);
        fun(mat,res,temp,0,0); 
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends