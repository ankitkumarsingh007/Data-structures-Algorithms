// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    string helper(int num,int n){
        num=num^(num>>1);
        string res="";
        
        while(num!=0){
            res+=char('0'+num%2);
            n--;
            num>>=1;
        }
        
        while(n--)
        res+='0';
        
        reverse(res.begin(),res.end());
        
        return res;
    }
    vector<string> graycode(int n)
    {
        vector<string> res;
        
        int l=pow(2,n);
        for(int i=0;i<l;i++){
            res.push_back(helper(i,n));
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
        
        Solution ob;
        vector<string> ans= ob.graycode(n);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
            
        cout<<"\n";
    }
}



  // } Driver Code Ends