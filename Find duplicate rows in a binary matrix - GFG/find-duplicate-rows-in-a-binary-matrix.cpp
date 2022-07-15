// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
struct Node{
    Node* child[2];
    bool end;
    Node(){
        child[0]=child[1]=NULL;
        end=false;
    }
};

class Solution
{   
public:
vector<int> repeatedRows(vector<vector<int>> matrix, int M, int N) 
{ 
    Node* root=new Node();
    vector<int> res;
    
    for(int i=0;i<M;i++){
        vector<int> v=matrix[i];
        Node* curr=root;
        for(int u:v){
            if(curr->child[u]==NULL)
            curr->child[u]=new Node();
            curr=curr->child[u];
        }
        if(!curr->end){
            curr->end=true;
        }
        else
        res.push_back(i);
    }
    
    return res;
} 
};


// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


  // } Driver Code Ends