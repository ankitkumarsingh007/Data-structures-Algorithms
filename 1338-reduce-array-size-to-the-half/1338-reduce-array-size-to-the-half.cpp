class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int x:arr)
            mp[x]++;
        
        vector<int> curr;
        for(auto x:mp)
            curr.push_back(x.second);
        
        sort(curr.begin(),curr.end());
        int n=curr.size();
        
        int i=n-1,sum=0,k=arr.size()/2;
        
        for(i;i>=0;i--){
            sum+=curr[i];
            if(sum>=k)
                break;
        }
        
        return n-i;
    }
};