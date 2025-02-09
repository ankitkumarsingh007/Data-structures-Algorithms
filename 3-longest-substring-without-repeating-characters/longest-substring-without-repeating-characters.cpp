class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(256,-1);
        int l=-1,res=0;
        
        for(int i=0;i<s.size();i++){
            if(pos[s[i]]!=-1)
            l=max(l,pos[s[i]]);

            res=max(res,i-l);
            pos[s[i]]=i;
        }

        return res;
    }
};