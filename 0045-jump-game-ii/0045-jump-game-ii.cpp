class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1)
            return 0;
        
        int step=1,reach=nums[0];
        
        while(reach<(n-1)){
            step++;
            int curr_max=reach;
            for(int i=1;i<=reach;i++){
                curr_max=max(curr_max,i+nums[i]);
            }
            
            reach=curr_max;
        }
        
        return step;
    }
};