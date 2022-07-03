class Solution {
public:
    void fun(string &s,vector<string>& dict,int n,vector<string> &res,string curr,int pos){
        if(pos==s.length())
        {
            res.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++){
            if(s.find(dict[i],pos)==pos){
                // take care that curr need not be updated in this function itself
                //it will be updated after subsequent function calls only
                string x=curr;
                if(pos==0)
                x+=dict[i];
                else
                {
                    x+=" ";
                    x+=dict[i];
                }
                fun(s,dict,n,res,x,pos+dict[i].length());
            }
        }
        return;
    }
    
    vector<string> wordBreak(string s, vector<string>& dict) {
        vector<string> res;
        string curr="";
        fun(s,dict,dict.size(),res,curr,0);
        return res;
    }
};