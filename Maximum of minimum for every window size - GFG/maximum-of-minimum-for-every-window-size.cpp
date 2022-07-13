// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    vector<int> prev,next;
    
    void prevSmall(int arr[],int n){
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i])
            st.pop();
            
            if(!st.empty())
            prev[i]=st.top();
            st.push(i);
        }
        return;
    }
    
    void nextSmall(int arr[],int n){
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])
            st.pop();
            
            if(!st.empty())
            next[i]=st.top();
            st.push(i);
        }
        return;
    }
    
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int> res(n,0);
        prev.clear(),next.clear();
        
        prev.resize(n,-1),next.resize(n,n);
        prevSmall(arr,n);
        nextSmall(arr,n);
        
        for(int i=0;i<n;i++){
            int a=next[i]-prev[i]-2;
            
            res[a]=max(res[a],arr[i]);
        }
        
        for(int i=n-2;i>=0;i--){
            res[i]=max(res[i],res[i+1]);
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends