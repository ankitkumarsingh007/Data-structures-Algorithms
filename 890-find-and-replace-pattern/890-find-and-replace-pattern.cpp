class Solution {
public:
    string helper(string s){
        int n=s.size();
        vector<int> pos(26,0);
        int cnt=1;
        
        string res="";
        for(char c:s){
            if(pos[c-'a']==0){
                pos[c-'a']=cnt++;
            }
            
            res+=(pos[c-'a']+'0');
        }
        
        return res;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        
        string check=helper(pattern);
        
        for(string &s:words){
            if(helper(s)==check)
                res.push_back(s);
        }
        
        return res;
    }
};