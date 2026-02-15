class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, res = INT_MAX;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (nums[mid] <= nums[r]) {
                res = min(res, nums[mid]);
                r = mid - 1;
            } else {
                res = min(res, nums[l]);
                l = mid + 1;
            }
        }

        return res;
    }
};