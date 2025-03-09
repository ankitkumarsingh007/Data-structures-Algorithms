class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,r=nums.size()-1;

        while(l<r){
            int mid = l+(r-l)/2;

            if(mid<r && nums[mid]==nums[mid+1]){
                if((mid-l)%2==1){
                    r=mid-1;
                }else{
                    l=mid+2;
                }
            }else if(mid>l && nums[mid]==nums[mid-1]){
                if((r-mid)%2==1){
                    l=mid+1;
                }else{
                    r=mid-2;
                }
            }else{
                return nums[mid];
            }
        }

        return nums[l];
    }
};