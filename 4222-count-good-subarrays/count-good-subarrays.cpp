class Solution {
public:
    typedef long long ll;
    long long countGoodSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> l(n), r(n);

        vector<int> arr(32, -1);

        for (int i = 0; i < n; i++) {
            int v = 0;
            for (int j = 0; j < 32; j++) {
                if (((1 << j) & nums[i]) == 0)
                    v = max(v, arr[j] + 1);
                else
                    arr[j] = i;
            }
            l[i] = v;
        }

        vector<int> arr1(32, n);
        for (int i = n - 1; i >= 0; i--) {
            int v = n - 1;
            for (int j = 0; j < 32; j++) {
                if (((1 << j) & nums[i]) == 0)
                    v = min(v, arr1[j] - 1);
                else
                    arr1[j] = i;
            }
            r[i] = v;
        }

        ll res = 0;
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.count(nums[i]))
                res += (r[i] - i + 1) * (i-max(mp[nums[i]]+1,l[i])+1);
            else
                res += ((r[i] - i + 1) * (i - l[i] + 1));
            mp[nums[i]]=i;
        }

        return res;
    }
};