class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1)
            return nums[0];
        
        int prev_prev=nums[0],prev=max(nums[0],nums[1]),a;
        
        for(int i=2;i<n;i++){
            a=max(prev,prev_prev+nums[i]);
            
            prev_prev=prev;
            prev=a;
        }
        
        return prev;
    }
};