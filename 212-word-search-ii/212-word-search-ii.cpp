class Solution {
public:
    vector<string> res;
    int x[4]={-1,1,0,0},y[4]={0,0,-1,1};
    int n,m;
    unordered_set<string> st;
    
    bool valid(int i,int j){
        if(i>=0 && i<n && j>=0 && j<m)
        return true;
        return false;
    }
    
    void dfs(vector<vector<char>>& board,int i,int j,string &curr){
        if(st.find(curr)!=st.end()){
            res.push_back(curr);
            st.erase(curr);
        }
        if(curr.length()==10)
            return;
        
        for(int k=0;k<4;k++){
            int a=i+x[k],b=j+y[k];
            
            if(valid(a,b) && board[a][b]!='&'){
                curr+=board[a][b];
                board[a][b]='&';
                
                dfs(board,a,b,curr);
                
                board[a][b]=curr.back();
                curr.pop_back();
            }
        }
        
        return;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	    n=board.size(),m=board[0].size();
	    
	    for(string &s:words){
	        st.insert(s);
	    }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string curr="";
                curr+=board[i][j];
                
                board[i][j]='&';
                
                dfs(board,i,j,curr);
                
                board[i][j]=curr.back();
            }
        }
	    
	    return res;
    }
};