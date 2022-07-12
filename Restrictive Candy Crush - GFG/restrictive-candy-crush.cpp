// { Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k,string s){
        if(k==1)
        return "";
        
        int n=s.size(),curr=1;
        stack<char> st;
        st.push(s[0]);
        
        for(int i=1;i<n;i++){
            st.push(s[i]);
            
            if(s[i]==s[i-1]){
                curr++;
                if(curr==k){
                    while(curr--)
                    st.pop();
                    curr=0;
                }
            }
            else
            curr=1;
        }
        
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        
        reverse(res.begin(),res.end());
        
        return res.size()==s.size()?res:Reduced_String(k,res);
    }


};

// { Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}  // } Driver Code Ends