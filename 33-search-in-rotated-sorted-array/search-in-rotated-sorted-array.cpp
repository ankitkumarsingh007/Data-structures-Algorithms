class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[m] == target)
                return m;
            // we need to take care of case when l==m, then if target has not
            // matched we want to do l=m+1 in any case and this case will help
            // in that, else it would have went to r=m-1 in next loop
            else if (nums[l] <= nums[m]) {
                // Make sure we are scoping down in confirm manner that result
                // will be in this part
                if (target < nums[m] && target >= nums[l])
                    r = m - 1;
                else
                    l = m + 1;
            } else {
                // Make sure we are scoping down in confirm manner that result
                // will be in this part
                if (target > nums[m] && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }

        return -1;
    }
};