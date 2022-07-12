// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The stoiction returns 1 if
s string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        vector<string> split(string s){
            int n=s.size();
            vector<string> res;
            
            for(int i=0;i<n;i++){
                string curr="";
                while(i<n){
                    if(s[i]=='.')
                    break;
                    curr+=s[i++];
                }
                res.push_back(curr);
            }
            
            return res;
        }
        
        int isValid(string s) {
            if (count(s.begin(), s.end(), '.') != 3) {
                return false;
            }
            vector<string> parts = split(s);
            
            
            if (parts.size() != 4) {
                return false;
            }
            for (string part : parts) {
                if (part.empty() || part.size() > 3 || part.size() > 1 && part[0] == '0') {
                    return false;
                }
                for (char c : part) {
                    if (!isdigit(c)) {
                        return false;
                    }
                }
                if (stoi(part) > 255) {
                    return false;
                }
            }
            return true;
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends