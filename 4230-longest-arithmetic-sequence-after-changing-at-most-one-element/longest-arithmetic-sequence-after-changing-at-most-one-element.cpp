class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n, 1), r(n, 1);

        for (int i = 1; i < n; i++) {
            if (i == 1 ||
                (nums[i] - nums[i - 1]) != (nums[i - 1] - nums[i - 2]))
                l[i] = 2;
            else
                l[i] = l[i - 1] + 1;
        }

        for (int i = (n - 2); i >= 0; i--) {
            if (i == (n - 2) ||
                (nums[i + 1] - nums[i]) != (nums[i + 2] - nums[i + 1]))
                r[i] = 2;
            else
                r[i] = r[i + 1] + 1;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                res = max(res, r[i + 1] + 1);
            } else if (i == (n - 1)) {
                res = max(res, l[i - 1] + 1);
            } else {
                res = max(res, max(l[i - 1], r[i + 1]) + 1);
                if (((nums[i - 1] - nums[i + 1]) % 2) == 0) {
                    int diff = (nums[i + 1] - nums[i - 1]) / 2;
                    int right = 1, left = 1;
                    if (i >= 2 && nums[i - 1] - nums[i - 2] == diff)
                        left = l[i - 1];
                    if (i < (n - 2) && nums[i + 2] - nums[i + 1] == diff)
                        right = r[i + 1];

                    res = max(res, left + right + 1);
                }
            }
        }

        return res;
    }
};