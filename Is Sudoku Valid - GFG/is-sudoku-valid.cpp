// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> arr){
        vector<int> row(9,0),col(9,0),block(9,0);
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(arr[i][j]==0)
                    continue;
                
                int b=((i/3)*3)+j/3,val=1<<(arr[i][j]);
                
                if(row[i]&val || col[j]&val || block[b]&val)
                    return false;
                row[i]|=val;
                col[j]|=val;
                block[b]|=val;
            }
        }
        
        return true;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends