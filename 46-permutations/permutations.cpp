class Solution {
public:
    void findPermute(vector<int> &nums,int i,int n,vector<vector<int>> &res){
        if(i==n){
            res.push_back(nums);
            return;
        }

        for(int j=i;j<n;j++){
            swap(nums[j],nums[i]);
            findPermute(nums,i+1,n,res);
            swap(nums[j],nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        findPermute(nums,0,nums.size(),res);

        return res;
    }
};