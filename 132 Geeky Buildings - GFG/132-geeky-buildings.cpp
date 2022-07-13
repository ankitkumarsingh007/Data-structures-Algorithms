// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
	bool recreationalSpot(int arr[], int n){
		int pre[n];
		pre[0]=arr[0];
		
		for(int i=1;i<n;i++)
		pre[i]=min(pre[i-1],arr[i]);
		
		stack<int> st;
		st.push(arr[n-1]);
		
		for(int i=n-2;i>0;i--){
		    while(!st.empty() && st.top()<=pre[i])
		    st.pop();
		    
		    if(!st.empty() && st.top()<arr[i])
		    return true;
		    
		    st.push(arr[i]);
		}
		
		return false;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution ob;
		if(ob.recreationalSpot(arr, n))
		    cout<<"True"<<endl;
		else
		    cout<<"False"<<endl;
	}
	return 0;
}  // } Driver Code Ends