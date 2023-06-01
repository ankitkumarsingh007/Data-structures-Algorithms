class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        v.push_back(nums[0]);
        
        int n=nums.size(),pos;
        
        for(int i=1;i<n;i++){
            if(nums[i]>v.back())
                v.push_back(nums[i]);
            else if(nums[i]<v.back()){
                pos=lower_bound(v.begin(),v.end(),nums[i])-v.begin();
                v[pos]=nums[i];
            }
        }
        
        return v.size();
    }
};