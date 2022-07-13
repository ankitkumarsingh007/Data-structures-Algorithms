// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++
class Solution {
 public:
   string findSum(string X, string Y) {
       // Your code goes here
       string s;
       bool flag=false;
       
       reverse(X.begin(),X.end());
       reverse(Y.begin(),Y.end());
       
       int s1=X.length();
       int s2=Y.length();
       int carry=0;
       
       int i=0;
       int j=0;
       
       while(i<s1 || j<s2){
           
           if (i>=s1){
               int sum=((Y[j]-'0')+carry)%10;
               carry=((Y[j]-'0')+carry)/10;
               s+=(sum+'0');
               j++;
           }
           
           else if (j>=s2){
               int sum=((X[i]-'0')+carry)%10;
               carry=((X[i]-'0')+carry)/10;
               s+=(sum+'0');
               i++;
           }
           
           else{
               int sum=((X[i]-'0')+(Y[j]-'0')+carry)%10;
               carry=((X[i]-'0')+(Y[j]-'0')+carry)/10;
               s+=(sum+'0');
               i++;
               j++;
           }
       }
       
       if(carry!=0){
           s+=(carry+'0');
       }
       
       for(int i=s.size()-1;i>0;i--){
           if(s[i]=='0')
           s.pop_back();
           else
           break;
       }

       reverse(s.begin(),s.end());

       return s ;       
   }
};



// { Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}  // } Driver Code Ends