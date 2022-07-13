// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        string res="";
        stack<char> st;
        
        for(char c:s){
            if(c=='.'){
                while(!st.empty()){
                    res+=st.top();
                    st.pop();
                }
                res+='.';
            }
            else
            st.push(c);
        }
        
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        
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
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends