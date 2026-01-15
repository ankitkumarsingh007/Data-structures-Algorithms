class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        vector<bool> taken(256,false);

        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                if(taken[t[i]]){
                    return false;
                }
                taken[t[i]]=true;
                mp[s[i]]=t[i];
            } else if(mp[s[i]]!=t[i])
            return false;
        }

        return true;
    }
};