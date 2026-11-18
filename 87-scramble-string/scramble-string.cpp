class Solution {
public:
    unordered_map<string,bool> mp;
    bool isScramble(string s1, string s2) {
        int n1=s1.size(), n2=s2.size();

        if(n1!=n2 || (n1==1 && s1!=s2))
        return false;

        if(s1==s2)
        return true;

        string key = s1+" "+s2;
        if(mp.find(key)!=mp.end())
        return mp[key];

        for(int i=1;i<n1;i++){
            bool withoutSwap = isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i));
            if(withoutSwap)
            return mp[key] = withoutSwap;

            bool withSwap = isScramble(s1.substr(0,i),s2.substr(n2-i)) && isScramble(s1.substr(i),s2.substr(0,n2-i));
            if(withSwap)
            return mp[key] = withSwap;
        }

        return mp[key] = false;
    }
};