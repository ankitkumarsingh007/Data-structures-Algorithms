// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    typedef pair<int,int> pp;
    int h[4]={-1,1,0,0},v[4]={0,0,-1,1};
    bool valid(int i,int j,int n,int m){
        if(i>=0 && i<n && j>=0 && j<m)
        return true;
        return false;
    }
    
    int helpaterp(vector<vector<int>> arr)
    {
        queue<pp> q;
        int n=arr.size(),m=arr[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==0)
                arr[i][j]=-1;
                else if(arr[i][j]==1)
                arr[i][j]=INT_MAX;
                else
                {
                    arr[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            pp p=q.front();
            q.pop();
            int a=p.first,b=p.second;
            
            for(int i=0;i<4;i++){
                int x=a+h[i],y=b+v[i];
                if(valid(x,y,n,m) && arr[x][y]==INT_MAX)
                {
                    q.push({x,y});
                    arr[x][y]=arr[a][b]+1;
                }
            }
        }
        
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]!=-1)
                res=max(res,arr[i][j]);
            }
        }
        
        if(res==INT_MAX)
        return -1;
        else
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
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends