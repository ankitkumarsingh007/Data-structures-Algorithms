class Solution {
public:
    typedef long long ll;
    vector<ll> arr;

    Solution() { arr.resize(100001, 0); }
    int findDuplicate(vector<int>& nums) {
        Solution();
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int index = nums[i] % n;
            arr[index] += (index)*ll(n);

            if ((arr[index] / n) > (index))
                return index;
        }

        // for(int i=1;i<n;i++){
        //     cout<<nums[i]/n << " ";
        //     if(nums[i]/n > i)
        //     return i;
        // }

        return -1;
    }
};