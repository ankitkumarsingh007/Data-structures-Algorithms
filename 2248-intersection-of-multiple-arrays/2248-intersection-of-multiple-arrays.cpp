class Solution {
public:
    vector<int> intersection(vector<vector<int>>& arr) {
        unordered_map<int,int> mp;
        
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int x:arr[i])
                mp[x]++;
        }
        
        vector<int> res;
        for(auto x:mp){
            if(x.second==n)
                res.push_back(x.first);
        }
        
        sort(res.begin(),res.end());
        return res;
    }
};