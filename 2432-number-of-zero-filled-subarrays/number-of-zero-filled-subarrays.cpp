class Solution {
public:
    typedef long long ll;
    long long zeroFilledSubarray(vector<int>& nums) {
        ll curr = 0, n = nums.size(), res = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                curr = 0;
                while (i < n && nums[i] == 0) {
                    curr++, i++;
                }

                res += (curr * (curr + 1)) / 2;
            }
        }

        return res;
    }
};