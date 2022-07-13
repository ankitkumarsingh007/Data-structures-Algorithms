// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<char>> arr;
    int n,m;
    string s;
    int x[4]={-1,1,0,0},y[4]={0,0,-1,1};
    
    bool valid(int i,int j){
        if(i>=0 && i<n && j>=0 && j<m && arr[i][j]!='&')
            return true;
        return false;
    }
    
    bool dfs(int i,int j,int ind){
        if(s[ind]!=arr[i][j])
            return false;
        if(s[ind]==arr[i][j] && ind==(s.size()-1))
            return true;
        
        char c=arr[i][j];
        arr[i][j]='&';
        for(int k=0;k<4;k++){
            int a=i+x[k],b=j+y[k];
            
            if(valid(a,b) && dfs(a,b,ind+1))
                return true;
        }
        
        arr[i][j]=c;
        return false;
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        arr=board;
        s=word;
        n=board.size(),m=board[0].size();
        
        if((n*m)<s.size())
            return false;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                if(arr[i][j]==s[0] && dfs(i,j,0))
                    return true;
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends