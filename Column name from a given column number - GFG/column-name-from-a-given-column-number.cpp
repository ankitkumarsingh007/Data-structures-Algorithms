// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    typedef long long int ll;
    
    string colName (long long int n)
    {
        if(n==1)
        return "A";
        
        vector<int> arr;
        while(n!=0){
            n--;
            arr.push_back(n%26);
            n/=26;
        }
        
        string res="";
        for(int i:arr){
            res+=char(i+'A');
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends