class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[m] == target)
                return m;
            // When l==m then we have to go to m+1 in any case and
            // nums[l]<=nums[m] gives us that else if its' nums[l]<nums[m] then
            // it gets r = m-1
            if (nums[l] <= nums[m]) {
                if (target >= nums[l] && target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            } else {
                if (target > nums[m] && target <= nums[r]) {
                    l = m + 1;
                } else
                    r = m - 1;
            }
        }

        return -1;
    }
};