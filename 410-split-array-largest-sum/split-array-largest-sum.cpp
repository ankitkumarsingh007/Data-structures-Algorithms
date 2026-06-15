class Solution {
public:
    bool valid(vector<int> &nums,int mid, int k){
        int cnt = 1, curr = 0;
        for(int a:nums){
            if((curr+a)>mid){
                cnt++;
                curr = a;
            }else
            curr+=a;
        }
        return cnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = INT_MIN, r = 0;

        for(int a:nums){
            l = max(l,a);
            r+=a;
        }

        int res = l;
        while(l<=r){
            int mid = l +(r-l)/2;
            if(valid(nums,mid,k)){
                res = mid,
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return res;
    }
};