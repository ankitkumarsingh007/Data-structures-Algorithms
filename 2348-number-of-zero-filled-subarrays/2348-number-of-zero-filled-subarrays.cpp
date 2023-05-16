class Solution {
public:
    typedef long long ll;
    long long zeroFilledSubarray(vector<int>& nums) {
        ll res=0,cnt=0;
        
        for(int x:nums){
            if(x==0){
                cnt++;
                res+=cnt;
            }
            else
                cnt=0;
        }
        
        return res;
    }
};