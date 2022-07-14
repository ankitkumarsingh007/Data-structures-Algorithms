// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    int x[8]={-1,-1,-1,0,0,1,1,1},y[8]={-1,0,1,-1,1,-1,0,1};
    int n,m;
    
    bool valid(int i,int j){
        if(i>=0 && i<n && j>=0 && j<m)
        return true;
        return false;
    }
    
    bool dfs(vector<vector<char>>& board,string s,int i,int j,int p){
        if(p==s.size())
        return true;
        char c=board[i][j];
        board[i][j]='&';
        
        for(int k=0;k<8;k++){
            int a=i+x[k],b=j+y[k];
            
            if(valid(a,b) && board[a][b]==s[p] && dfs(board,s,a,b,p+1)){
                board[i][j]=c;
                return true;
            }
        }
        
        board[i][j]=c;
        return false;
    }
    
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& words) {
	   vector<string> res;
	    n=board.size(),m=board[0].size();
	    unordered_set<string> st;
	    
	    for(string &s:words){
	        if(st.find(s)!=st.end())
	        continue;
	        st.insert(s);
	        for(int i=0;i<n;i++){
	            for(int j=0;j<m;j++){
	                if(board[i][j]==s[0] && dfs(board,s,i,j,1)){
	                    res.push_back(s);
	                    break;
	                }
	            }
	            
                if(res.size()!=0 && res.back()==s)
                break;
	        }
	        
	    }
	    
	    return res;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends