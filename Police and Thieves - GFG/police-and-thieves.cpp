// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        int res=0;
        
        deque<int> dq;
        
        for(int i=0;i<n;i++){
            if(!dq.empty()){
                if(arr[dq.front()]=='P' && arr[i]=='T')
                {
                    res++;
                    dq.pop_front();
                }
                else if(arr[dq.front()]=='T' && arr[i]=='P')
                {
                    res++;
                    dq.pop_front();
                }
                else{
                    dq.push_back(i);
                }
            }
            else{
                dq.push_back(i);
            }
            
            if(!dq.empty() && dq.front()==(i-k))
            dq.pop_front();
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 

  // } Driver Code Ends