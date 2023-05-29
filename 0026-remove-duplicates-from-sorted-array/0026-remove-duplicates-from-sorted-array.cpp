class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=1,r=1,n=nums.size();
        
        while(r<n){
            if(nums[r]==nums[l-1]){
                r++;
            }
            else{
                nums[l++]=nums[r++];
            }
        }
        
        return l;
    }
};