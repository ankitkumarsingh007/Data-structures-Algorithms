class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        
        for(int x:arr)
            mp[x]++;
        
        vector<int> v;
        for(auto x:mp){
            v.push_back(x.second);
        }
        
        sort(v.begin(),v.end());
        
        int l=0;
        while(k!=0){
            if(k>=v[l]){
                k-=v[l];
                l++;
            }
            else
                break;
        }
        
        return v.size()-l;
    }
};