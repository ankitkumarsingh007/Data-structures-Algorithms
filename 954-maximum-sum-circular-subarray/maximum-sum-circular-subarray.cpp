class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int res1 = nums[0], curr_max = nums[0], totalSum = nums[0];
        nums[0] = -nums[0];

        for (int i = 1; i < nums.size(); i++) {
            curr_max = max(curr_max + nums[i], nums[i]);
            res1 = max(res1, curr_max);
            totalSum += nums[i];
            nums[i] = -nums[i];
        }

        if (res1 <= 0)
            return res1;

        int res2 = nums[0];
        curr_max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            curr_max = max(curr_max + nums[i], nums[i]);
            res2 = max(res2, curr_max);
        }

        return max(res1, totalSum + res2);
    }
};