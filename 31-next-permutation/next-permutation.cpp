class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int r = n - 1;
        while (r != 0 && nums[r - 1] >= nums[r])
            r--;

        if (r == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int l = r - 1, pos = r;
        for (int i = r; i < n; i++) {
            if (nums[i] > nums[l])
                pos = i;
        }

        swap(nums[l], nums[pos]);

        // Revesing decreasing sequence makes seuqence sorted
        reverse(nums.begin() + r, nums.end());
        return;
    }
};