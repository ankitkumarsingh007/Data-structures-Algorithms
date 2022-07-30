class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> count(26,0);
        
        for(string &s:words2){
            vector<int> temp(26,0);
            
            for(char &c:s)
                temp[c-'a']++;
            
            for(int i=0;i<26;i++)
                count[i]=max(count[i],temp[i]);
        }
        
        vector<string> res;
        
        for(string &s:words1){
            vector<int> temp(26,0);
            
            for(char &c:s)
                temp[c-'a']++;
            
            int i;
            for(i=0;i<26;i++)
                if(temp[i]<count[i])
                    break;
            
            if(i==26) 
            res.push_back(s);
        }
        
        return res;
    }
};