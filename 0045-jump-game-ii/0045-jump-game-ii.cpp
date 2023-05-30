class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        
        int step=0;
        int reach=0;
        int prev=0;
        
        while(reach<(n-1)){
            step++;
            int curr_max=reach;
            for(int i=prev;i<=reach;i++){
                curr_max=max(curr_max,i+nums[i]);
            }
            
            prev=reach+1;
            reach=curr_max;
        }
        
        return step;
    }
};