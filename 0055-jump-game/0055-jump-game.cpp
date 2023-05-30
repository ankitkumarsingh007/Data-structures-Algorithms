class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int last=1,i;
        
        for(i=0;i<min(n,last);i++){
            last=max(last,i+nums[i]+1);
        }
        
        return i==n;
    }
};