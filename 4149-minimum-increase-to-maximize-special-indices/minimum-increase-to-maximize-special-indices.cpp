typedef long long ll;
class Solution {
public:
    vector<ll> dp;
    int n;
    ll fun(vector<int>& nums, int i) {
        if (i == (n - 2))
            return max(max(nums[i + 1], nums[i - 1]) + 1 - nums[i], 0);
        if (i == (n - 3)) {
            ll val1 = max(max(nums[i + 1], nums[i - 1]) + 1 - nums[i], 0);
            ll val2 = max(max(nums[i + 2], nums[i]) + 1 - nums[i + 1], 0);
            return min(val1, val2);
        }
        if (dp[i] != -1)
            return dp[i];

        ll val = max(max(nums[i + 1], nums[i - 1]) + 1 - nums[i], 0);
        if ((i % 2) == 0) {
            return dp[i] = fun(nums, i + 2) + val;
        } else {
            return dp[i] = min(fun(nums, i + 2) + val, fun(nums, i + 1));
        }
        return dp[i];
    }
    long long minIncrease(vector<int>& nums) {
        ll res = 0;
        n = nums.size();
        dp.resize(n, -1);

        if (n % 2) {
            for (int i = 1; i < n; i += 2) {
                res += max(max(nums[i - 1], nums[i + 1]) + 1 - nums[i], 0);
            }
            return res;
        } else {
            return fun(nums, 1);
        }
        return res;
    }
};