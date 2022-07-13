// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    typedef long long ll;
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<ll> st;
        vector<ll> res(n,-1);
        // st.push(arr[n-1]);
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]>=st.top())
            st.pop();
            if(!st.empty())
            res[i]=st.top();
            
            st.push(arr[i]);
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
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends