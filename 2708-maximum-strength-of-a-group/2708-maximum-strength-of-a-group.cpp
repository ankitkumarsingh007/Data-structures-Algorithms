class Solution {
public:
    typedef long long ll;
    
    ll helper(vector<int> &nums,int pos,ll mul){
        if(pos==-1)
            return mul;
        
        return max(helper(nums,pos-1,mul*nums[pos]),helper(nums,pos-1,mul));
    }
    
    long long maxStrength(vector<int>& nums) {
        
        int pos=0,neg=0,zero=0;
        for(int a:nums){
            if(a==0)
                zero++;
            else if(a>0)
                pos++;
            else
                neg++;
        }
        
        ll res=helper(nums,nums.size()-1,1);
        
        if(pos!=0){
            return res;
        }
        else{
            if(neg>=2)
                return res;
            else if(zero)
                return 0;
            else{
                sort(nums.begin(),nums.end());
                return nums[0];
            }
        }
    }
};