// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    int sum=0,ans=0;
	    unordered_map<int,int> mp;
	    
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	        
	        sum%=k;
	        
	        if(sum==0)
	        ans=max(ans,i+1);
	        //why that's required even if all constraints are in limit
	        if(sum<0)
	        sum+=k;
	        
	        if(mp.find(sum)!=mp.end())
	        ans=max(ans,i-mp[sum]);
	        else
	        mp[sum]=i;
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends