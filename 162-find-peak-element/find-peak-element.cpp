class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size();
        while (l <= r) {
            int mid = (l + r) / 2;
            bool leftCheck = (mid == 0 || nums[mid] > nums[mid - 1]);
            bool rightCheck =
                (mid == (nums.size() - 1) || nums[mid] > nums[mid + 1]);

            if (leftCheck && rightCheck)
                return mid;
            else if (leftCheck)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return 0;
    }
};