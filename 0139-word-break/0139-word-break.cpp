class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(string s:wordDict)
            st.insert(s);
        
        int n=s.size();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        
        for(int i=1;i<=n;i++){
            string curr;
            for(int j=i-1;j>=0;j--){
                if(dp[j]){
                    curr=s.substr(j,i-j);
                    if(st.find(curr)!=st.end()){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        
        return dp[n];
    }
};