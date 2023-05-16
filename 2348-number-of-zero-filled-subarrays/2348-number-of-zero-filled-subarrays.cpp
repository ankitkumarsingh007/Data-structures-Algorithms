class Solution {
public:
    typedef long long ll;
    long long zeroFilledSubarray(vector<int>& nums) {
        ll res=0;
        
        ll start=-1,end,n=nums.size();
        
        for(ll i=0;i<n;i++){
            if(nums[i]==0){
                if(start==-1)
                    start=i;
                end=i;
            }
            else{
                if(start!=-1){
                    ll a=end-start+1;
                    res+=(a*(a+1))/2;
                }
                
                start=-1;
            }
        }
        
        if(start!=-1){
            ll a=end-start+1;
            res+=(a*(a+1))/2;
        }
        
        return res;
    }
};