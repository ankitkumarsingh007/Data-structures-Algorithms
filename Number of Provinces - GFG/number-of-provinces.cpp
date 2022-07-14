// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<bool> visit;
    
    void dfs(vector<vector<int>> adj,int i,int v){
        visit[i]=true;
        
        for(int j=0;j<v;j++){
            if(!visit[j] && adj[i][j]==1)
            dfs(adj,j,v);
        }
        return;
    }
    
    int numProvinces(vector<vector<int>> adj, int v) {
        visit.resize(v,false);
        
        int res=0;
        for(int i=0;i<v;i++){
            if(!visit[i]){
                dfs(adj,i,v);
                res++;
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
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends