class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        int prev_prev = nums[0], prev = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int curr = max(prev_prev + nums[i], prev);
            prev_prev = prev;
            prev = curr;
        }

        return prev;
    }
};