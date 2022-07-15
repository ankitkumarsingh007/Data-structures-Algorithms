// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    
    int longestSubsequence(int n, int a[])
    {
       vector<int> dp(n);
       int l=0,r=0;
       dp[0]=a[0];
       
       for(int i=1;i<n;i++){
           if(a[i]>dp[r]){
               r++;
               dp[r]=a[i];
           }
           else{
               int x=upper_bound(dp.begin(),dp.begin()+r,a[i])-dp.begin();
               
               if(x!=0 && dp[x-1]==a[i])
                   continue;
               
               dp[x]=a[i];
           }
       }
       
       return r+1;
    }
};



// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends