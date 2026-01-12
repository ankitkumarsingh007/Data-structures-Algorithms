class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, res = INT_MAX, curr_sum = 0;

        while (r < nums.size()) {
            curr_sum += nums[r++];
            if (curr_sum >= target) {
                while (curr_sum >= target) {
                    curr_sum -= nums[l++];
                }
                res = min(res, r - l + 1);
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};