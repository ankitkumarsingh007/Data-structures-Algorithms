class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        
        if(n<3)
            return n;
        
        int l=2,r=2;
        
        while(r<n){
            if(nums[l-1]==nums[l-2] && nums[l-1]==nums[r])
                r++;
            else{
                nums[l++]=nums[r++];
            }
        }
        
        return l;
    }
};