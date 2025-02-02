class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n=arr.size(),res=arr[0],curr_max=arr[0];
        for(int i=1;i<n;i++){
            curr_max=max(curr_max+arr[i],arr[i]);
            res=max(res,curr_max);
        }

        return res;
    }
};