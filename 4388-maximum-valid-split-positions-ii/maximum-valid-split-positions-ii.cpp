class Solution {
public:
    int getVal(vector<int>& nums, int i) {
        int n = nums.size();
        vector<int> arr;
        for (int j = 0; j < n; j++) {
            if (j != i)
                arr.push_back(nums[j]);
        }

        n = arr.size();

        vector<int> pre(n, 0), suf(n);

        for (int i = 1; i < n; i++) {
            pre[i] = gcd(pre[i - 1], arr[i - 1]);
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == (n - 1))
                suf[i] = arr[i];
            else
                suf[i] = gcd(suf[i + 1], arr[i]);
        }

        int res = 0;

        for (int i = 0; i < n; i++) {
            if (pre[i] == suf[i])
                res++;
        }

        return res;
    }

    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);

        for (int i = 1; i < n; i++) {
            pre[i] = gcd(pre[i - 1], nums[i - 1]);
        }

        int res = 0;

        for (int i = 0; i <= n; i++) {
            // This value is not changing gcd so explicit care not needed, Also
            // wanted to take 0 by default
            if (i > 0 && pre[i] == pre[i - 1])
                continue;

            // for 0, skip val will -1, So no one skipped
            res = max(res, getVal(nums, i - 1));
        }

        return res;
    }
};