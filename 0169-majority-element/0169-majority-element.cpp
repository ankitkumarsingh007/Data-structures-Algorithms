class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=nums[0],cnt=1,n=nums.size();
        
        for(int i=1;i<n;i++){
            if(nums[i]==res)
                cnt++;
            else{
                cnt--;
                if(cnt==0)
                    res=nums[i],cnt=1;
            }
        }
        
        return res;
    }
};