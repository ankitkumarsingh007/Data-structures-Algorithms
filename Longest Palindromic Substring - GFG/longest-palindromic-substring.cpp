// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s){
        int n=s.size();
        int start=0,size=1;
        
        for(int i=1;i<n;i++)
        {
            int l=i-1;
            int h=i;
            //even part
            while(l>=0 && h<n && s[l]==s[h])
            {
                if((h-l+1)>size)
                {
                    start=l;
                    size=h-l+1;
                }
                l--;
                h++;
            }
            
            l=i-1;
            h=i+1;
            //odd part
            while(l>=0 && h<n && s[l]==s[h])
            {
                if((h-l+1)>size)
                {
                    start=l;
                    size=h-l+1;
                }
                l--;
                h++;
            }
        }
        
        return s.substr(start,size);
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends