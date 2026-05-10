class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int n = nums.size();
        vector<int> prefix(n+1,0);

        for(int i=1;i<=n;i++)
        prefix[i]+=(prefix[i-1]+(nums[i-1]%2==0));

        for(auto v: queries){
            int l = v[0], r=v[1], k =v[2];
            int l_cnt = (nums[l]-1)/2 , r_cnt = nums[r]/2 , rem = prefix[r+1]-prefix[l];

            if(l_cnt>=k)
            res.push_back(2*k);
            else if((r_cnt-rem)<k){
                res.push_back(2*(k+rem));
            }else{
                int s = l, e = r;
                while(s<=e){
                    int m = s+(e-s)/2;
                    int r_cnt = nums[m]/2, rem = prefix[m+1]-prefix[l];
                    if((r_cnt-rem)<k) s=m+1;
                    else e=m-1;
                }
                rem = prefix[s]-prefix[l];
                res.push_back(2*(k+rem));
            }
        }

        return res;
    }
};