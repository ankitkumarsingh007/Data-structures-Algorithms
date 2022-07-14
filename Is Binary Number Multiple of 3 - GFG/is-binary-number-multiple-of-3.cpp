// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    int odd=0,even=0;
	    
	    for(int i=0;i<s.size();i++){
	        if(s[i]=='1'){
	            if(i%2==0)
	            even++;
	            else
	            odd++;
	        }
	    }
	    
	    if((even-odd)%3==0)
	    return true;
	    else
	    return false;
	}

};

// { Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}

  // } Driver Code Ends