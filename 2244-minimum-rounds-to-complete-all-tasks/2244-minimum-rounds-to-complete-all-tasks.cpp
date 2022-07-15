class Solution {
public:
    
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(int i:tasks)
            mp[i]++;
        
        int res=0;
        for(auto x:mp){
            if(x.second==1)
                return -1;
            res+=ceil(x.second/3.0);
        }
        
        return res;
    }
};