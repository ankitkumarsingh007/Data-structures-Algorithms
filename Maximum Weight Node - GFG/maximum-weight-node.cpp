//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int n, vector<int> edge)
  {
      vector<int> arr(n,0);
      
      for(int i=0;i<n;i++){
          if(edge[i]!=-1)
          arr[edge[i]]+=i;
      }
      
      int res=n-1;
      for(int i=n-2;i>=0;i--){
          if(arr[i]>arr[res])
          res=i;
      }
      
      return res;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends