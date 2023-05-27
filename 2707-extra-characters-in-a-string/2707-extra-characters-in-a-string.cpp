class Solution {
public:
    unordered_set<string> st;
    
    vector<vector<int>> dp;
    
    int helper(string s,int pos,string curr){
        if(pos==s.size())
            return curr.size();
        if(dp[pos][curr.size()]!=-1)
            return dp[pos][curr.size()];
        
        string add=curr+s[pos];
        
        int res=INT_MAX;
        
        if(st.find(add)!=st.end()){
            res=helper(s,pos+1,"");
        }
        res=min(res,int(helper(s,pos+1,add)));
        res=min(res,int(curr.size()+1)+helper(s,pos+1,""));
        
        return dp[pos][curr.size()]=res;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        dp.resize(s.size()+1,vector<int>(s.size()+1,-1));
        
        for(string s:dictionary){
            st.insert(s);
        }
        
        return helper(s,0,"");
    }
};