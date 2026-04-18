class Solution {
public:
    typedef long long ll;
    int n;
    bool firstTaken;
    vector<vector<ll>> dp;
    ll fun(vector<int>& cost, int i, int k) {
        if (k == 0)
            return 0;
        if (i >= n || (i == (n - 1) && firstTaken))
            return INT_MAX;
        if (dp[i][k] != -1)
            return dp[i][k];

        return dp[i][k] =
                   min(cost[i] + fun(cost, i + 2, k - 1), fun(cost, i + 1, k));
    }
    int minOperations(vector<int>& nums, int k) {
        n = nums.size();
        if ((k) > (n / 2))
            return -1;
        if (k == 0)
            return 0;

        vector<int> cost;
        cost.push_back(max(0, max(nums[n - 1], nums[1]) + 1 - nums[0]));
        for (int i = 1; i < (n - 1); i++) {
            cost.push_back(max(0, max(nums[i - 1], nums[i + 1]) + 1 - nums[i]));
        }
        cost.push_back(max(0, max(nums[0], nums[n - 2]) + 1 - nums[n - 1]));

        dp.resize(n, vector<ll>(k + 1, -1));
        firstTaken = true;
        int a = cost[0] + fun(cost, 2, k - 1);

        dp.clear();
        dp.resize(n, vector<ll>(k + 1, -1));
        firstTaken = false;
        int b = fun(cost, 1, k);

        return min(a, b);
    }
};