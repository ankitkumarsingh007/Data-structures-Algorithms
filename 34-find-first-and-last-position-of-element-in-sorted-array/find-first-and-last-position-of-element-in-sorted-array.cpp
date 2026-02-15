class Solution {
public:
    int getPos(vector<int>& nums, int target, bool start) {
        int l = 0, r = nums.size() - 1, res = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                res = mid;
                if (start) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {getPos(nums, target, true), getPos(nums, target, false)};
    }
};